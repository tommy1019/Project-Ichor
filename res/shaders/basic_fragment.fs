#version 120

uniform sampler2D texture;
uniform sampler2D normalMap;

varying vec3 vPos;
varying vec3 vNormal;
varying vec2 vTexCoord;

void main()
{
    vec3 eyePos = vec3(0, 0, 0);
    vec3 lightPos = vec3(-1, 1, 1);

    vec3 finalNormal = vNormal;// * texture2D(normalMap, vTexCoord).xyz;
    vec4 surfaceColor = texture2D(texture, vTexCoord);
    vec3 surfaceToLight = normalize(lightPos - vPos);

    float diffuseFactor = clamp(dot(finalNormal, surfaceToLight), 0, 1);
    
    vec3 vertexToEye = normalize(eyePos - vPos);
    vec3 reflected = normalize(reflect(-surfaceToLight, finalNormal));
    float specularFactor = max(dot(vertexToEye, reflected), 0);

    vec4 pixelBrightness = diffuseFactor * vec4(1.0, 1.0, 1.0, 1.0) + vec4(0.1, 0.1, 0.1, 0.1);
 
    if (specularFactor > 0)
    {
        specularFactor = pow(specularFactor, 64);
        pixelBrightness *= specularFactor; 

        gl_FragColor = vec4(0, 0, 1, 1) * specularFactor;
    }

    //gl_FragColor = pixelBrightness * surfaceColor;
}
