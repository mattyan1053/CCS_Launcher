# pragma once
# include <Siv3D.hpp>
# include "Defines.hpp"

class InfoLoader {
private:

	FilePath m_folderPath;

	AppData loadAppData(const FilePath& path);

public:

	InfoLoader(const FilePath& path);

	Array<AppInfo> Load();

};