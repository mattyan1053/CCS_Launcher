# pragma once
# include <Siv3D.hpp>
# include "Select.hpp"

void Select::init() {

	// �X�N���[���V���b�g�A�C�e��
	SelectItem::setItemNum(m_data->apps.size());
	for (size_t i = 0; i < (m_data->apps).size(); i++) {
		m_items.emplace_back(i, m_data->apps[i]);
	}

	// �T�v��
	m_frameSummary.set(summaryPos, summarySize);

	// �{�^��
	m_detailButton.set(buttonPos, buttonSize, L"���킵������");

}

void Select::updateLauncher() {

	// �A�C�e���̈ړ�
	const int32 wheelY = Mouse::Wheel();
	SelectItem::moveItemPos(wheelY);

	// �e�A�C�e���̏�ԍX�V
	for (auto& item : m_items) {
		if (item.update(m_data->selectedID)) {
			m_data->selectedID = item.id;
		}
	}

	// �N���b�N����ʑJ��
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

	// �^�C�g��
	FontAsset(L"title")(L"CCS ��i�W").draw(10, 10);

	// �A�C�e���A�C�R���̕`��
	for (const auto& item : m_items) {
		if (item.id == m_data->selectedID) continue;
		item.draw();
	}
	m_items[m_data->selectedID].draw(); // �e�̕`��̂��߂ɑI�𒆂̂��̂����Ō�ɕ`��

	// ���̕`��
	RoundRect(m_frameSummary, 30).drawShadow({ 2.0, 2.0, }, 2.0, 2.0);
	RoundRect(m_frameSummary, 30).draw(Palette::White);
	FontAsset(L"summary")(L"�Q�[�����F" + m_data->apps[m_data->selectedID].name).draw(40, 500, Palette::Black);
	FontAsset(L"summary")(L"�W�������F" + m_data->apps[m_data->selectedID].appData.kind).draw(40, 530, Palette::Black);
	FontAsset(L"summary")(L"����F" + m_data->apps[m_data->selectedID].appData.usingtext).draw(40, 560, Palette::Black);

	m_detailButton.draw();

}