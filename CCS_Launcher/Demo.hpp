# pragma once
# include <Siv3D.hpp>
# include <HamFramework.hpp>
# include "Scene.hpp"

/// <summary>
/// デモシーン総括クラス
/// </summary>
struct DemoData {

	/// <summary>
	/// 再生中のID
	/// </summary>
	int32 playingID;

	/// <summary>
	/// アプリケーション数
	/// </summary>
	unsigned int appsNum;

	/// <summary>
	/// アプリケーションデータ(ShareDataを参照)
	/// </summary>
	Array<AppInfo> apps;

	std::function<void(String)> changeBaseScene;

};

using DemoSceneChanger = SceneManager<int32, DemoData>;

class Demo : public BaseScene {
private:

	/// <summary>
	/// シーン遷移マネージャー
	/// </summary>
	DemoSceneChanger m_manager;

public:

	/// <summary>
	/// デフォルトコンストラクタ
	/// </summary>
	Demo() = default;

	/// <summary>
	/// シーン遷移されたときの初期化
	/// </summary>
	void init() override;

	/// <summary>
	/// シーンの更新
	/// </summary>
	void updateLauncher() override;

	/// <summary>
	/// シーンの描画
	/// </summary>
	void draw() const override;

};
