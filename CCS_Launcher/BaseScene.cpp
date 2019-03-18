# pragma once
# include <Siv3D.hpp>
# include <Windows.h>
# include "Scene.hpp"

# define NOMINMAX

void BaseScene::update() {

	// �N�����̃A�v���P�[�V����������΍ŏ����A�I��������ŏ�������
	// �N�����̃A�v�����Ȃ���Ώ��X�V
	if (m_data->process) {
		if (m_data->process->isRunning()) {
			Window::Minimize();
		}
		else {
			Window::Restore();
			m_data->process = none;
		}
	}
	else if (m_data->handle) {
		if (m_data->handle == 0 || WaitForSingleObject(m_data->handle, 0) == WAIT_OBJECT_0) {
			CloseHandle(m_data->handle); // �g�p�̂�������n���h���̓N���[�Y
			m_data->handle = 0;
			Window::Restore();
		}
		else {
			Window::Minimize();
		}
	}
	else {
		updateLauncher();
	}

}

