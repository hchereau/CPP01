#include "sed.hpp"

bool	read_file(const std::string& path, std::string& out) {
	std::ifstream ifs(path.c_str(), std::ios::in | std::ios::binary);
	if (!ifs)
		return false;
	std::ostringstream oss; oss << ifs.rdbuf(); out = oss.str();
	return true;
}

bool write_file(const std::string& path, const std::string& data) {
    std::ofstream ofs(path.c_str(), std::ios::out | std::ios::binary | std::ios::trunc);
    if (!ofs) {
        return false;
    }
    ofs << data;
    return ofs.good();
}

std::string replace_all(const std::string& text,
						const std::string& s1,
						const std::string& s2)
{
	if (s1.empty())
		return text;
	std::string res; res.reserve(text.size());
	std::string::size_type start = 0;
	while (true) {
		std::string::size_type pos = text.find(s1, start);
		if (pos == std::string::npos) {
			res.append(text, start, std::string::npos);
			break;
		}
		res.append(text, start, pos - start);
		res.append(s2);
		start = pos + s1.size();
	}
	return res;
}
