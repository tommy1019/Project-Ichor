varying vec3 pos;
varying vec3 normal;

void main()
{
    vec3 n = normal;
    vec3 l = vec3(-1,1,1);

    float cosTheta = max(0.0, dot(n,l)) * 0.6;

    //gl_FragColor = vec4(normal, 1.0);
    gl_FragColor = vec4(1.0, 1.0, 1.0, 1.0) * cosTheta + vec4(0.1, 0.1, 0.1, 1.0);
}
