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
		// Probably, some enums for your own commands?..
		};
	};
	struct Rto {
		enum {
		// Here indexes of your RTOs...
		};
	};
};

struct RTOEvent {
	int sign;
	int info;

	RTOEvent(int eventSign, int eventInfo) { sign = eventSign; info = eventInfo; }
};
