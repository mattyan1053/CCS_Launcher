# pragma once
# include <Siv3D.hpp>

/// <summary>
/// リソースロード用クラス
/// </summary>
class ResourceLoader {

public:

	/// <summary>
	/// デフォルトコンストラクタ
	/// </summary>
	ResourceLoader() = default;

	/// <summary>
	/// データのロード。すべてAsset。
	/// </summary>
	void load();

	/// <summary>
	/// フォントのロード
	/// </summary>
	void loadFonts();

	/// <summary>
	/// 画像のロード
	/// </summary>
	void loadTextures();

};