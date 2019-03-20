# pragma once
# include <Siv3D.hpp>
# include <Windows.h>
# include "Detail.hpp"

# define NOMINMAX
# undef CreateProcess

void Detail::init() {

	// �{�^���̐ݒ�
	m_startButton.set(startButtonPos, buttonSize, L"������");
	m_backButton.set(backButtonPos, buttonSize, L"���ǂ�");

	// �T�v���̐ݒ�
	m_kind.set(tagPos, tagSize, L"�Q�[���W�������F" + m_data->apps[m_data->selectedID].appData.kind);
	m_usetext.set(tagPos + Point(0, tagSize.y + 20), tagSize, L"����F" + m_data->apps[m_data->selectedID].appData.usingtext);

	// Readme�@�ݒ�
	frame = InlineFrame(Rect(readmePos, readmeSize));

	// ����Đ�
	if (m_data->apps[m_data->selectedID].isMovieExist) {
		m_data->apps[m_data->selectedID].appData.demo.play();
	}

}

void Detail::updateLauncher() {

	// ����X�V
	if (m_data->apps[m_data->selectedID].isMovieExist) {
		if (Window::Focused() && !m_data->apps[m_data->selectedID].appData.demo.isPlaying()) m_data->apps[m_data->selectedID].appData.demo.play();
		m_data->apps[m_data->selectedID].appData.demo.update();
	}
	
	// �����`���[���A�N�e�B�u�łȂ��Ƃ��|�[�Y
	if (m_data->apps[m_data->selectedID].isMovieExist && m_data->apps[m_data->selectedID].appData.demo.isPlaying() && Window::Focused() == false) {
		m_data->apps[m_data->selectedID].appData.demo.pause();
	}

	// �߂�
	if (m_backButton.update()) {
		if (m_data->apps[m_data->selectedID].isMovieExist) {
			m_data->apps[m_data->selectedID].appData.demo.stop();
		}
		changeScene(L"Select");
	}

	// �V��
	if (m_startButton.update()) {
		if (m_data->apps[m_data->selectedID].isMovieExist) {
			m_data->apps[m_data->selectedID].appData.demo.pause();
		}
		
		// EXE�`���ȊO�̃t�@�C����ShellExecuteEx���g�p���ĊJ���Ă���B
		// EXE�`���̃t�@�C����ShellExecute�Ŗ��Ȃ��ƍl�����邪�A����̈���ɕs�������邽�߈ꉞ�c���Ă���
		if (FileSystem::Extension(m_data->apps[m_data->selectedID].appData.executePath) == L"exe") {
			m_data->process = System::CreateProcess(m_data->apps[m_data->selectedID].appData.executePath);
		}
		else {
			m_data->handle = openOtherApps(FileSystem::FileName(m_data->apps[m_data->selectedID].appData.executePath), FileSystem::ParentPath(m_data->apps[m_data->selectedID].appData.executePath));
		}

	}

	frame.update(m_data->apps[m_data->selectedID].appData.readme.size);

}

void Detail::draw() const{

	// �^�C�g��

	const Mat3x2 mat = Mat3x2::Rotate(-5_deg, screenshotPos);
	{
		const Transformer2D transformer(mat, true);
		const Rect screenshotFrame(screenshotPos, screenshotSize);
		const auto ty = [=](KineticTypography& k) {
			k.pos.x += k.index * 4;
		};
		// �^�C�g���̕��������傫���ꍇ�͏������t�H���g���g��
		if (FontAsset(L"title2")(m_data->apps[m_data->selectedID].name).region().w < screenshotSizeX + 50) {
			FontAsset(L"title2")(m_data->apps[m_data->selectedID].name).drawKinetic(marginLeft, marginTop, ty);
		}
		else {
			FontAsset(L"title3")(MakeTailCutString(m_data->apps[m_data->selectedID].name, screenshotSizeX + 50, L"title3")).drawKinetic(marginLeft, marginTop, ty);
		}
		screenshotFrame.drawShadow({ 6, 6 }, 3, 5);
		if (m_data->apps[m_data->selectedID].isMovieExist) {
			screenshotFrame(m_data->apps[m_data->selectedID].appData.demo.getFrameTexture().resize(screenshotSize)).draw().drawFrame(10, 0, Palette::Black).drawFrame(11, 0, Palette::White);
		}
		else {
			screenshotFrame(m_data->apps[m_data->selectedID].appData.screenshot.resize(screenshotSize)).draw().drawFrame(10, 0, Palette::Black).drawFrame(11, 0, Palette::White);
		}
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

# define NOMINMAX

HANDLE Detail::openOtherApps(const FilePath & file, const FilePath & directory) {

	SHELLEXECUTEINFO shellExeInfo;
	memset(&shellExeInfo, 0, sizeof(shellExeInfo));
	shellExeInfo.cbSize = sizeof(shellExeInfo);
	shellExeInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
	shellExeInfo.lpVerb = L"open";
	shellExeInfo.lpFile = file.c_str();
	shellExeInfo.lpParameters = nullptr;
	shellExeInfo.lpDirectory = directory.c_str();
	shellExeInfo.nShow = SW_SHOWNORMAL;

	ShellExecuteExW(&shellExeInfo);

	HANDLE handle = shellExeInfo.hProcess;

	return handle;

}