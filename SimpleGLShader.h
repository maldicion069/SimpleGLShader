// Simplify GLSL C style interaction with C++
// Copyright (C) <2015> - Cristian Rodr�guez Bernal (maldicion069)

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef _SIMPLEGLSHADER_H_
#define _SIMPLEGLSHADER_H_

#define MAX_SHADERS 2

#include <GL/glew.h>
#include <map>
#include <string>

class SimpleGLShader {
public:
	SimpleGLShader(void);
	~SimpleGLShader(void);

	void load_from_source(const std::string& source, GLenum shader_type);
	void load_from_file(const std::string& file, GLenum shader_type);

	void create_and_link();
	void use();
	void unuse();

	void add_attribute(const std::string& attr);
	void add_uniform(const std::string& uniform);

	GLuint attribute(const std::string& attr);
	GLuint uniform(const std::string& uniform);

private:
	GLuint mProgram;
	int mTotalShaders;
	std::map<std::string, GLuint> mAttrsList;
	std::map<std::string, GLuint> mUniformList;
	enum ShaderType {V_SHADER, F_SHADER};
	GLuint mShaders[MAX_SHADERS];
};

#endif /* _SIMPLEGLSHADER_H_ */