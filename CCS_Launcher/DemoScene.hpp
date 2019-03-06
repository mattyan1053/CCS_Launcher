# pragma once
# include <Siv3D.hpp>
# include <HamFramework.hpp>
# include "Demo.hpp"
# include "Tag.hpp"

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

	/// <summary>
	/// アプリケーション名タグ位置
	/// </summary>
	Point m_tagPos = { 920, -20 };

	/// <summary>
	/// アプリケーション名タグサイズ
	/// </summary>
	const Size m_tagSize = { 400, 80 };

	/// <summary>
	/// 画面に映すテクスチャのサイズ
	/// </summary>
	Size m_textureSize;

	/// <summary>
	/// 画面に映すテクスチャの拡大率
	/// </summary>
	double m_scaleUpRate;

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