#version 150

uniform mat4 u_Model;
uniform mat4 u_ViewProj;

in vec4 vs_Pos;
in vec4 vs_Col;

uniform mat4 u_BindMats[100];
uniform mat4 u_OverallTransform[100];

in ivec2 vs_JointID;
in vec2 vs_JointWeight;

out vec4 fs_Col;

void main() {
    fs_Col = vs_Col;

    // negative weight implies shader is drawing a joint
    if (vs_JointWeight[0] < 0) {
        vec4 modelposition = u_Model * vs_Pos;

        //built-in things to pass down the pipeline
        gl_Position = u_ViewProj * modelposition;
    } else {
        int idx_1 = vs_JointID[0];
        int idx_2 = vs_JointID[1];

        vec4 infl_1 = u_OverallTransform[idx_1] * u_BindMats[idx_1] * vs_Pos;
        vec4 infl_2 = u_OverallTransform[idx_2] * u_BindMats[idx_2] * vs_Pos;

        vec4 influenced = (vs_JointWeight[0] * infl_1) + (vs_JointWeight[1] * infl_2);

        vec4 modelposition = u_Model * influenced;

        //built-in things to pass down the pipeline
        gl_Position = u_ViewProj * modelposition;
    }
}

