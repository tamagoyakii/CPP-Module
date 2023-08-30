#include <iostream>
#include <fstream>

int main(int ac, char** av) {
	if (ac != 4) {
		std::cout << "wrong arguments" << std::endl;
		return 0;
	}

	std::string fileName(av[1]);
	std::string s1(av[2]);
	std::string s2(av[3]);
	std::string buf;

	if (s1.empty()) {
		std::cout << "nothing to change" << std::endl;
		return 0;
	}

  std::ifstream fin (fileName, std::ios::in);
  if (fin.fail()) {
		std::cout << "file open failed" << std::endl;
		return 0;
	}

	std::ofstream fout (fileName + ".replace", std::ios::out);
	if (fout.fail()) {
		std::cout << "file create failed" << std::endl;
		return 0;
	}

	while (std::getline(fin, buf, '\0') && !std::cin.eof()) {
		if (s1.compare(s2)) {
			for (size_t pos = buf.find(s1, 0); pos != std::string::npos; pos = buf.find(s1, pos + s2.size())) {
				buf.erase(pos, s1.length());
				buf.insert(pos, s2);
			}
		}
		fout << buf;
	}
	fin.close();
	fout.close();
  return 0;
}