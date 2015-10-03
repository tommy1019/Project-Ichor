uniform sampler2D tex;

varying vec3 pos;
varying vec3 normal;
varying vec2 texCoord;

void main()
{
    vec3 n = normal;
    vec3 l = vec3(-1,1,1);

    float cosTheta = max(0.0, dot(n,l)) * 0.6;

    //gl_FragColor = vec4(normal, 1.0);
    gl_FragColor = (texture2D(tex, texCoord)) * cosTheta + vec4(0.1, 0.1, 0.1, 1.0);
}
