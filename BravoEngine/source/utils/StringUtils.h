#pragma once
#include <vector>
#include <string>
#include <glm/glm.hpp>

namespace StringUtils {

	void Split(std::string& str, std::vector<std::string>& tokens, const char separator) {
		size_t lastIndex = str.find_first_not_of(separator, 0);
		size_t index = str.find_first_of(separator, 0);
		while (lastIndex != std::string::npos || index != std::string::npos) {
			tokens.emplace_back(str.substr(lastIndex, index -  lastIndex));
			lastIndex = str.find_first_not_of(separator, index);
			index = str.find_first_of(separator, lastIndex);
		}
	}

	glm::vec4 StrToVec4(std::string& str) {
		// (0,0,0,0)
		std::string vec = str.substr(1, str.size() - 1);
		std::vector<std::string> vec4Str;
		StringUtils::Split(vec, vec4Str, ',');
		return glm::vec4(std::stof(vec4Str[0]), std::stof(vec4Str[1]),
			std::stof(vec4Str[2]), std::stof(vec4Str[3]));
	}



}