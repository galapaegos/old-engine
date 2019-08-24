#ifndef _gsevents_h_
#define _gsevents_h_

namespace gs
{
	enum GSEVENT
	{
		GS_SLEEP,		// whoah horsey, sleep
		GS_ADD_SCENE,
		GS_ADD_SCENE_FILE,
		GS_SAVE_SCENE,
		GS_REM_SCENE,
		GS_LOAD_SCENE,

		//camera events
		GS_CAMERA,		// sets the camera for a scene intially.  updating the camera *should* be handled by update
		GS_CAMERA_UPDATE,

		GS_CAMERA_MOVE_F,
		GS_CAMERA_MOVE_L,
		GS_CAMERA_MOVE_U,

		GS_CAMERA_YAW,
		GS_CAMERA_PITCH,
	};
};

#endif

