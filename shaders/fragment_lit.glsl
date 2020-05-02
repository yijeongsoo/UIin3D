uniform sampler2D diffuse;
uniform vec2 lightPosition;
// You could add a second light!


varying vec2 texCoordVar;
varying vec2 varPosition;

float attenuate(float dist, float a, float b) {
	return 1.0 / (1.0 + (a * dist) + (b * dist * dist));
}

void main() {
	float brightness = attenuate(distance(lightPosition, varPosition), 1.0, 0.0);
	vec4 color = texture2D(diffuse, texCoordVar);
	gl_FragColor = vec4(color.rgb * brightness * 1.5, color.a);
}