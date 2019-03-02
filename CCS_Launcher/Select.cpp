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
	m_demoButton.set(demoButtonPos, buttonSize, L"Demo");

	m_leftButton.set(leftButtonPos, moveButtonRadius, L"��");
	m_rightButton.set(rightButtonPos, moveButtonRadius, L"��");

	stopwatch.start();

}

void Select::updateLauncher() {

	// ���Ԍo�߂ɂ��Demo���[�r�[�̋N��( 2 ���}�E�X����Ȃ�)
	if (Mouse::Delta() != Point::Zero) {
		stopwatch.reset();
		stopwatch.start();
	}
	else {
		if (!stopwatch.isActive()) stopwatch.start();
	}
	if (stopwatch.min() >= 2) {
		changeScene(L"Demo");
	}

	// �A�C�e���̈ړ�
	const int32 wheelY = Mouse::Wheel();
	SelectItem::moveItemPos(wheelY);

	// �e�A�C�e���̏�ԍX�V
	for (auto& item : m_items) {
		if (item.update(m_data->selectedID)) {
			m_data->selectedID = item.id;
		}
	}

	//�A�C�e���ړ��{�^��
	if (m_leftButton.update() && SelectItem::checkPos() != 1) {
		m_moveFlag -= m_items[0].getItemWidth() * 3;
	}
	if (m_rightButton.update() && SelectItem::checkPos() != 2) {
		m_moveFlag += m_items[0].getItemWidth() * 3;
	}

	if (m_moveFlag != 0) {
		if (m_moveFlag > 0) {
			if (m_moveFlag >= 100) m_moveFlag -= 100;
			else m_moveFlag = 0;
			SelectItem::moveItemPos(1);
		}
		else {
			if (m_moveFlag <= -100) m_moveFlag += 100;
			else m_moveFlag = 0;
			SelectItem::moveItemPos(-1);
		}
		return; // �X�N���[�����͑���s�\��
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

	if (m_demoButton.update()) {
		changeScene(L"Demo");
	}

}

void Select::draw() const {

	// �w�i
	TextureAsset(L"ccslogo").resize(500, 500).draw(Window::Size() - Point(470, 370));

	// �^�C�g��
	FontAsset(L"title")(L"CCS Works").draw(50, 10);

	// �A�C�e���A�C�R���̕`��
	for (const auto& item : m_items) {
		if (item.id == m_data->selectedID) continue;
		item.draw();
	}
	m_items[m_data->selectedID].draw(); // �e�̕`��̂��߂ɑI�𒆂̂��̂����Ō�ɕ`��

	// ���̕`��
	RoundRect(m_frameSummary, 30).drawShadow({ 2.0, 2.0, }, 2.0, 2.0);
	RoundRect(m_frameSummary, 30).draw(Palette::White);
	FontAsset(L"summary")(L"�Q�[�����F" + m_data->apps[m_data->selectedID].name).draw(summaryPos.x + 20, summaryPos.y + summaryMarginTop, Palette::Black);
	FontAsset(L"summary")(L"�W�������F" + m_data->apps[m_data->selectedID].appData.kind).draw(summaryPos.x + 20, summaryPos.y + summaryMarginTop + 40, Palette::Black);
	FontAsset(L"summary")(L"����F" + m_data->apps[m_data->selectedID].appData.usingtext).draw(summaryPos.x + 20, summaryPos.y + summaryMarginTop + 40 * 2, Palette::Black);

	m_detailButton.draw();
	m_demoButton.draw();
	if (SelectItem::checkPos() != 1) {
		m_leftButton.draw();
	}
	if (SelectItem::checkPos() != 2) {
		m_rightButton.draw();
	}

}