# pragma once
# include <Siv3D.hpp>
# include "Select.hpp"

void Select::init() {

	// スクリーンショットアイテム
	SelectItem::setItemNum(m_data->apps.size());
	for (size_t i = 0; i < (m_data->apps).size(); i++) {
		m_items.emplace_back(i, m_data->apps[i]);
	}

	// 概要欄
	m_frameSummary.set(summaryPos, summarySize);

	// ボタン
	m_detailButton.set(buttonPos, buttonSize, L"くわしく見る");

}

void Select::updateLauncher() {

	// アイテムの移動
	const int32 wheelY = Mouse::Wheel();
	SelectItem::moveItemPos(wheelY);

	// 各アイテムの状態更新
	for (auto& item : m_items) {
		if (item.update(m_data->selectedID)) {
			m_data->selectedID = item.id;
		}
	}

	// クリック時画面遷移
	for (size_t i = 0; i < m_items.size(); i++) {
		if (m_items[i].checkClick()) {
			m_data->selectedID = i;
			changeScene(L"Detail");
		}
	}
	if (m_detailButton.update()) {
		changeScene(L"Detail");
	}

}

void Select::draw() const {

	// タイトル
	FontAsset(L"title")(L"CCS 作品集").draw(10, 10);

	// アイテムアイコンの描画
	for (const auto& item : m_items) {
		if (item.id == m_data->selectedID) continue;
		item.draw();
	}
	m_items[m_data->selectedID].draw(); // 影の描画のために選択中のものだけ最後に描画

	// 情報の描画
	RoundRect(m_frameSummary, 30).drawShadow({ 2.0, 2.0, }, 2.0, 2.0);
	RoundRect(m_frameSummary, 30).draw(Palette::White);
	FontAsset(L"summary")(L"ゲーム名：" + m_data->apps[m_data->selectedID].name).draw(40, 500, Palette::Black);
	FontAsset(L"summary")(L"ジャンル：" + m_data->apps[m_data->selectedID].appData.kind).draw(40, 530, Palette::Black);
	FontAsset(L"summary")(L"操作：" + m_data->apps[m_data->selectedID].appData.usingtext).draw(40, 560, Palette::Black);

	m_detailButton.draw();

}