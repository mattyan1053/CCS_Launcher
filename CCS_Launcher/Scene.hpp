# pragma once
# include <Siv3D.hpp>
# include <HamFramework.hpp>
# include "Defines.hpp"

/// <summary>
/// シーン遷移で共有するデータ
/// </summary>
struct ShereData {

	/// <summary>
	/// 選択中のアプリケーションID
	/// </summary>
	unsigned int selectedID;

	/// <summary>
	/// アプリケーション情報の配列
	/// </summary>
	Array<AppInfo> apps;

	/// <summary>
	/// プロセスの実行フラグ
	/// </summary>
	Optional<ProcessInfo> process;
};

using SceneChanger = SceneManager<String, ShereData>;