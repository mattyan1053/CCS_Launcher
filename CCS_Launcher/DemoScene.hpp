# pragma once
# include <Siv3D.hpp>
# include <HamFramework.hpp>
# include "Demo.hpp"

/// <summary>
/// デモシーンクラス
/// </summary>
class DemoScene : public DemoSceneChanger::Scene {

private:

	/// <summary>
	/// 自身のID
	/// </summary>
	int32 m_id;

	/// <summary>
	/// 動画かスクリーンショットか
	/// </summary>
	bool m_isVideo;

	/// <summary>
	/// スクリーンショット表示間隔管理用
	/// </summary>
	Stopwatch m_stopwatch;

	/// <summary>
	/// 表示間隔
	/// </summary>
	int32 waitTime = 10;

public:

	/// <summary>
	/// デフォルトコンストラクタ
	/// </summary>
	DemoScene() = default;

	/// <summary>
	/// シーン遷移時
	/// </summary>
	void init() override;

	/// <summary>
	/// 情報更新
	/// </summary>
	void update() override;

	/// <summary>
	/// 画面更新
	/// </summary>
	void draw() const override;

};