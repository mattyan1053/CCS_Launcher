# pragma once
# include <Siv3D.hpp>
# include "Scene.hpp"
# include "Defines.hpp"
# include "InfoLoader.hpp"
# include "Select.hpp"
# include "Detail.hpp"

/// <summary>
/// ランチャー本体総括クラス
/// </summary>
class Launcher {
private:

	/// <summary>
	/// シーン遷移マネージャー
	/// </summary>
	SceneChanger m_manager;

	/// <summary>
	/// ディレクトリ情報のローダー
	/// </summary>
	InfoLoader m_infoLoader;

public:

	/// <summary>
	/// コンストラクタ
	/// pathのディレクトリのランチャーになる。
	/// </summary>
	/// <param name = "path">
	/// ランチャーとしたいディレクトリのパス
	/// </param>
	Launcher(const FilePath& path);

	/// <summary>
	/// ランチャーの開始
	/// </summary>
	void start();
};