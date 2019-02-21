# pragma once
# include <Siv3D.hpp>
# include "Scene.hpp"

bool CheckWindowState(Optional<ProcessInfo> process) {

	// �N�����̃A�v���P�[�V����������΍ŏ����A�I��������ŏ�������
	if (process) {
		if (process->isRunning()) {
			Window::Minimize();
		}
		else {
			Window::Restore();
			process = none;
		}
		return false;
	}

	return true;

}

void BaseScene::update() {

	// �N�����̃A�v���̏�Ԃ��`�F�b�N���Ă�����X�V
	if (CheckWindowState(m_data->process)) {
		updateLauncher();
	}

}

