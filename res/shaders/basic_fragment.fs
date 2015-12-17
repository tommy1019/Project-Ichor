#version 120

uniform sampler2D texture;
uniform sampler2D normalMap;

varying vec3 vPos;
varying vec3 vNormal;
varying vec2 vTexCoord;

void main()
{
    vec3 eyePos = vec3(0, 0, 0);
    vec3 lightDirection = normalize(vec3(0, 0, 1));

    vec3 finalNormal = vNormal * texture2D(normalMap, vTexCoord).xyz;
    vec4 surfaceColor = texture2D(texture, vTexCoord);

    float diffuseFactor = clamp(dot(finalNormal, lightDirection), 0, 1);
  
    vec3 eyeDir = normalize(eyePos - vPos); 
    vec3 reflect = normalize(reflect(lightDirection, finalNormal));
    float specular = dot(eyeDir, reflect);
 
    vec4 pixelBrightness = diffuseFactor * vec4(1.0, 1.0, 1.0, 1.0) + vec4(0.1, 0.1, 0.1, 0.1);
 
    if (specular > 0)
    {
        pixelBrightness += pow(specular, 128) * vec4(1.0, 1.0, 1.0, 1.0);
    }

    gl_FragColor = pixelBrightness * surfaceColor;
}
