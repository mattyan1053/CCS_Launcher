# pragma once
# include <Siv3D.hpp>
# include "Defines.hpp"

/// <summary>
/// ディレクトリ内アプリケーション情報
/// </summary>
class InfoLoader {

private:

	/// <summary>
	/// 情報を取得するディレクトリのパス
	/// </summary>
	FilePath m_folderPath;

	/// <summary>
	/// デモムービー存在フラグ
	/// </summary>
	bool m_isMovieExist;

	/// <summary>
	/// アプリケーションの情報を取得します。
	/// </summary>
	/// <param name = "path">
	/// 情報を取得するアプリケーションのディレクトリ
	/// </param>
	/// <returns>
	/// 読み取ったアプリケーション情報(AppData型)
	/// </returns>
	AppData loadAppData(const FilePath& path);

public:

	/// <summary>
	/// コンストラクタ
	/// 受け取ったパスを登録します。
	/// </summary>
	/// <param name="path">
	/// 登録するディレクトリのパス
	/// </param>
	InfoLoader(const FilePath& path) : m_folderPath(path) {};

	/// <summary>
	/// ディレクトリ内のアプリケーション情報一覧を取得します。
	/// </summary>
	/// <returns>
	/// ディレクトリ内のアプリケーション情報(AppInfo)の配列
	/// </returns>
	Array<AppInfo> load();

};