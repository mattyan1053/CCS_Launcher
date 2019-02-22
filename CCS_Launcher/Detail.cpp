# pragma once
# include <Siv3D.hpp>
# include "Detail.hpp"

void Detail::init() {

	// �{�^���̐ݒ�
	m_startButton.set(startButtonPos, buttonSize, L"������");
	m_backButton.set(backButtonPos, buttonSize, L"���ǂ�");

	// �T�v���̐ݒ�
	m_kind.set(tagPos, tagSize, L"�Q�[���W�������F" + m_data->apps[m_data->selectedID].appData.kind);
	m_usetext.set(tagPos + Point(0, tagSize.y + 20), tagSize, L"����F" + m_data->apps[m_data->selectedID].appData.usingtext);

	frame = InlineFrame(Rect(readmePos, readmeSize));

}

void Detail::updateLauncher() {

	// �߂�
	if (m_backButton.update()) {
		changeScene(L"Select");
	}

	// �V��
	if (m_startButton.update()) {
		m_data->process = System::CreateProcess(m_data->apps[m_data->selectedID].appData.executePath);
	}

	frame.update(m_data->apps[m_data->selectedID].appData.readme.size);

}

void Detail::draw() const{

	// �^�C�g��

	const Mat3x2 mat = Mat3x2::Rotate(-5_deg, screenshotPos);
	{
		const Transformer2D transformer(mat, true);
		const Rect frame(screenshotPos, screenshotSize);
		FontAsset(L"title")(m_data->apps[m_data->selectedID].name).draw(marginLeft, marginTop);
		frame.drawShadow({ 6, 6 }, 3, 5);
		frame(m_data->apps[m_data->selectedID].appData.screenshot.resize(screenshotSize)).draw().drawFrame(10, 0, Palette::Black).drawFrame(11, 0, Palette::White);
	}

	// �t�
	m_kind.draw();
	m_usetext.draw();

	// �{�^��
	m_startButton.draw();
	m_backButton.draw();

	// Readme
	FontAsset(L"subtitle")(L"Read me !!").draw(readmePos.x, 30);
	const InlineFrameData frameData = frame.getFrameData();
	frameData.contentsArea.draw(Palette::White);
	Texture& texture = m_data->apps[m_data->selectedID].appData.readme;
	texture(frameData.contentsOffset, Min(frameData.contentsArea.w, texture.width), Min(frameData.contentsArea.h, texture.height)).draw(frameData.contentsArea.pos);
	frame.draw();
	frameData.region.drawFrame(0, 1.5, Palette::Gray);

}