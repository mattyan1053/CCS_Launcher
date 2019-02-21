# pragma once
# include <Siv3D.hpp>
# include "Scene.hpp"

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
	else {
		updateLauncher();
	}

}

