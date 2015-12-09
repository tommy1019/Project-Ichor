uniform sampler2D texture;
uniform sampler2D normalMap;

varying vec3 posOut;
varying vec3 normalOut;
varying vec2 texCoordOut;

void main()
{
    vec3 n = normalOut * (texture2D(normalMap, texCoordOut)).xyz;
    vec3 l = vec3(-1,1,1);

    float distance = length(l - posOut);

    float cosTheta = max(0.0, dot(n,l));

    vec3 r = reflect(-l, n);
    float cosAlpha = max(0.0, dot(vec3(0,0,0), r));

    gl_FragColor = texture2D(texture, texCoordOut);//vec4(n, 1.0);

//    gl_FragColor = (texture2D(texture, texCoordOut)) * ((cosTheta * 50.0 / (distance * distance)) + (pow(cosAlpha,5.0) * 50.0 / (distance * distance)) + vec4(0.1, 0.1, 0.1, 1.0));
}
