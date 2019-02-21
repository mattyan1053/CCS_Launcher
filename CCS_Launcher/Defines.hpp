# pragma once
# include <Siv3D.hpp>

/// <summary>
/// アプリケーションのデータ本体
/// </summary>
struct AppData {

	/// <summary>
	/// 実行ファイルのパス
	/// </summary>
	FilePath executePath;

	/// <summary>
	/// スクリーンショットのTexture
	/// </summary>
	Texture screenshot;

	/// <summary>
	/// ゲームジャンル
	/// </summary>
	String kind;

	/// <summary>
	/// 操作端末
	/// </summary>
	String usingtext;

	/// <summary>
	/// readmeの内容
	/// </summary>
	String readme;
};

/// <summary>
/// アプリケーション情報
/// </summary>
struct AppInfo {

	/// <summary>
	/// アプリケーションのID（読み込み順）
	/// </summary>
	unsigned int id;

	/// <summary>
	/// アプリケーション名（表示名）
	/// </summary>
	String name;

	/// <summary>
	/// アプリケーションの本データ
	/// </summary>
	AppData appData;
};