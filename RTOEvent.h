#pragma once

struct RTOEv {
	struct Sign {
		enum {
			CLOSE_WINDOW,
			CHANGE_RTO,
			SET_FPS_LIMIT,
		};
	};
	struct Info {
		enum {

		};
	};
	struct Rto {
		enum {
			MAINMENU_RTO,
			ACTION_RTO,
		};
	};
};

struct RTOEvent {
	int sign;
	int info;

	RTOEvent(int eventSign, int eventInfo) { sign = eventSign; info = eventInfo; }
};