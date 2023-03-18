// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//
// http://go.microsoft.com/fwlink/?LinkId=248926
// http://go.microsoft.com/fwlink/?LinkId=248929
// http://go.microsoft.com/fwlink/?LinkID=615561
// http://create.msdn.com/en-US/education/catalog/sample/stock_effects


struct ColorPair
{
    float3 Diffuse;
    float3 Specular;
};


ColorPair ComputeLights(float3 eyeVector, float3 worldNormal, uniform int numLights)
{
    float3x3 LightDirections = 0;
    float3x3 LightDiffuse = 0;
    float3x3 LightSpecular = 0;
    float3x3 halfVectors = 0;
    
    [unroll]
    for (int i = 0; i < numLights; i++)
    {
        LightDirections[i] = LightDirection[i];
        LightDiffuse[i]    = LightDiffuseColor[i];
        LightSpecular[i]   = LightSpecularColor[i];
        
        halfVectors[i] = normalize(eyeVector - LightDirections[i]);
    }

    float3 dotL = mul(-LightDirections, worldNormal);
    float3 dotH = mul(halfVectors, worldNormal);
    
    float3 zeroL = step(0, dotL);

    float3 diffuse  = zeroL * dotL;
    float3 specular = pow(max(dotH, 0) * zeroL, SpecularPower) * dotL;

    ColorPair result;
    
    result.Diffuse  = mul(diffuse,  LightDiffuse)  * DiffuseColor.rgb + EmissiveColor;
    result.Specular = mul(specular, LightSpecular) * SpecularColor;

    return result;
}


CommonVSOutput ComputeCommonVSOutputWithLighting(float4 position, float3 normal, uniform int numLights)
{
    CommonVSOutput vout;
    
    float4 pos_ws = mul(position, World);
    float3 eyeVector = normalize(EyePosition - pos_ws.xyz);
    float3 worldNormal = normalize(mul(normal, WorldInverseTranspose));

    ColorPair LightResult = ComputeLights(eyeVector, worldNormal, numLights);
    
    vout.Pos_ps = mul(position, WorldViewProj);
    vout.Diffuse = float4(LightResult.Diffuse, DiffuseColor.a);
    vout.Specular = LightResult.Specular;
    vout.FogFactor = ComputeFogFactor(position);
    
    return vout;
}


struct CommonVSOutputPixelLighting
{
    float4 Pos_ps;
    float3 Pos_ws;
    float3 Normal_ws;
    float  FogFactor;
};


CommonVSOutputPixelLighting ComputeCommonVSOutputPixelLighting(float4 position, float3 normal)
{
    CommonVSOutputPixelLighting vout;
    
    vout.Pos_ps = mul(position, WorldViewProj);
    vout.Pos_ws = mul(position, World).xyz;
    vout.Normal_ws = normalize(mul(normal, WorldInverseTranspose));
    vout.FogFactor = ComputeFogFactor(position);
    
    return vout;
}


#define SetCommonVSOutputParamsPixelLighting \
    vout.PositionPS = cout.Pos_ps; \
    vout.PositionWS = float4(cout.Pos_ws, cout.FogFactor); \
    vout.NormalWS = cout.Normal_ws;

