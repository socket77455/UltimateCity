/*
    SA-MP Streamer Plugin v2.3.6
    Copyright � 2010 Incognito

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#if defined _streamer_included
	#endinput
#endif
#define _streamer_included
#pragma library streamer

// Definitions

#define STREAMER_TYPE_OBJECT (0)
#define STREAMER_TYPE_PICKUP (1)
#define STREAMER_TYPE_CP (2)
#define STREAMER_TYPE_RACE_CP (3)
#define STREAMER_TYPE_MAP_ICON (4)
#define STREAMER_TYPE_3D_TEXT_LABEL (5)

// Enumerator

enum
{
	E_STREAMER_ATTACHED_PLAYER,
	E_STREAMER_ATTACHED_VEHICLE,
	E_STREAMER_COLOR,
	E_STREAMER_DISTANCE,
	E_STREAMER_DRAW_DISTANCE,
	E_STREAMER_EXTRA_ID,
	E_STREAMER_INTERIOR_ID,
	E_STREAMER_MARKER_TYPE,
	E_STREAMER_MODEL_ID,
	E_STREAMER_NEXT_X,
	E_STREAMER_NEXT_Y,
	E_STREAMER_NEXT_Z,
	E_STREAMER_PLAYER_ID,
	E_STREAMER_R_X,
	E_STREAMER_R_Y,
	E_STREAMER_R_Z,
	E_STREAMER_SIZE,
	E_STREAMER_SPEED,
	E_STREAMER_TEST_LOS,
	E_STREAMER_TYPE,
	E_STREAMER_WORLD_ID,
	E_STREAMER_X,
	E_STREAMER_Y,
	E_STREAMER_Z
}

// Natives (Settings)

native Streamer_TickRate(rate);
native Streamer_MaxItems(type, items);
native Streamer_VisibleItems(type, items);

// Natives (Updates)

native Streamer_Update(playerid);
native Streamer_UpdateEx(playerid, Float:x, Float:y, Float:z);

// Natives (Data Manipulation)

native Streamer_GetFloatData(type, {Text3D,_}:id, data, &Float:result);
native Streamer_GetIntData(type, {Text3D,_}:id, data);
native Streamer_SetFloatData(type, {Text3D,_}:id, data, Float:value);
native Streamer_SetIntData(type, {Text3D,_}:id, data, value);

// Natives (Objects)

native CreateDynamicObject(modelid, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, worldid = -1, interiorid = -1, playerid = -1, Float:distance = 200.0);
native DestroyDynamicObject(objectid);
native IsValidDynamicObject(objectid);
native SetDynamicObjectPos(objectid, Float:x, Float:y, Float:z);
native GetDynamicObjectPos(objectid, &Float:x, &Float:y, &Float:z);
native SetDynamicObjectRot(objectid, Float:rx, Float:ry, Float:rz);
native GetDynamicObjectRot(objectid, &Float:rx, &Float:ry, &Float:rz);
native MoveDynamicObject(objectid, Float:x, Float:y, Float:z, Float:speed);
native StopDynamicObject(objectid);
native DestroyAllDynamicObjects();
native CountDynamicObjects();

// Natives (Pickups)

native CreateDynamicPickup(modelid, type, Float:x, Float:y, Float:z, worldid = -1, interiorid = -1, playerid = -1, Float:distance = 100.0);
native DestroyDynamicPickup(pickupid);
native IsValidDynamicPickup(pickupid);
native DestroyAllDynamicPickups();
native CountDynamicPickups();

// Natives (Checkpoints)

native CreateDynamicCP(Float:x, Float:y, Float:z, Float:size, worldid = -1, interiorid = -1, playerid = -1, Float:distance = 100.0);
native DestroyDynamicCP(checkpointid);
native IsValidDynamicCP(checkpointid);
native TogglePlayerDynamicCP(playerid, checkpointid, toggle);
native TogglePlayerAllDynamicCPs(playerid, toggle);
native IsPlayerInDynamicCP(playerid, checkpointid);
native DestroyAllDynamicCPs();
native CountDynamicCPs();

// Natives (Race Checkpoints)

native CreateDynamicRaceCP(type, Float:x, Float:y, Float:z, Float:nextx, Float:nexty, Float:nextz, Float:size, worldid = -1, interiorid = -1, playerid = -1, Float:distance = 100.0);
native DestroyDynamicRaceCP(checkpointid);
native IsValidDynamicRaceCP(checkpointid);
native TogglePlayerDynamicRaceCP(playerid, checkpointid, toggle);
native TogglePlayerAllDynamicRaceCPs(playerid, toggle);
native IsPlayerInDynamicRaceCP(playerid, checkpointid);
native DestroyAllDynamicRaceCPs();
native CountDynamicRaceCPs();

// Natives (Map Icons)

native CreateDynamicMapIcon(Float:x, Float:y, Float:z, markertype, color, worldid = -1, interiorid = -1, playerid = -1, Float:distance = 100.0);
native DestroyDynamicMapIcon(iconid);
native IsValidDynamicMapIcon(iconid);
native DestroyAllDynamicMapIcons();
native CountDynamicMapIcons();

// Natives (3D Text Labels)

native Text3D:CreateDynamic3DTextLabel(text[], color, Float:x, Float:y, Float:z, Float:drawdistance, attachedplayer = INVALID_PLAYER_ID, attachedvehicle = INVALID_VEHICLE_ID, testlos = 0, worldid = -1, interiorid = -1, playerid = -1, Float:distance = 100.0);
native DestroyDynamic3DTextLabel(Text3D:id);
native IsValidDynamic3DTextLabel(Text3D:id);
native UpdateDynamic3DTextLabelText(Text3D:id, color, text[]);
native DestroyAllDynamic3DTextLabels();
native CountDynamic3DTextLabels();

// Natives (Internals)

native Streamer_AddPlayer(playerid);
native Streamer_RemovePlayer(playerid);
native Streamer_CheckPickup(playerid, pickupid);
native Streamer_RegisterInterface();

// Callbacks

forward OnDynamicObjectMoved(objectid);
forward OnPlayerPickUpDynamicPickup(playerid, pickupid);
forward OnPlayerEnterDynamicCP(playerid, checkpointid);
forward OnPlayerLeaveDynamicCP(playerid, checkpointid);
forward OnPlayerEnterDynamicRaceCP(playerid, checkpointid);
forward OnPlayerLeaveDynamicRaceCP(playerid, checkpointid);

// Automatic Setup System

static
	bool:Streamer_g_OPC = false,
	bool:Streamer_g_OPDC = false,
	bool:Streamer_g_OPPP = false,
	bool:Streamer_g_RI = false;

public
	OnFilterScriptInit()
{
	if (!Streamer_g_RI)
	{
		Streamer_g_OPC = funcidx("Streamer_OnPlayerConnect") != -1;
		Streamer_g_OPDC = funcidx("Streamer_OnPlayerDisconnect") != -1;
		Streamer_g_OPPP = funcidx("Streamer_OnPlayerPickUpPickup") != -1;
		Streamer_g_RI = true;
		Streamer_RegisterInterface();
	}
	if (funcidx("Streamer_OnFilterScriptInit") != -1)
	{
		return CallLocalFunction("Streamer_OnFilterScriptInit", "");
	}
	return 1;
}

#if defined _ALS_OnFilterScriptInit
	#undef OnFilterScriptInit
#else
	#define _ALS_OnFilterScriptInit
#endif
#define OnFilterScriptInit Streamer_OnFilterScriptInit

forward
	Streamer_OnFilterScriptInit();

public
	OnGameModeInit()
{
	if (!Streamer_g_RI)
	{
		Streamer_g_OPC = funcidx("Streamer_OnPlayerConnect") != -1;
		Streamer_g_OPDC = funcidx("Streamer_OnPlayerDisconnect") != -1;
		Streamer_g_OPPP = funcidx("Streamer_OnPlayerPickUpPickup") != -1;
		Streamer_g_RI = true;
		Streamer_RegisterInterface();
	}
	if (funcidx("Streamer_OnGameModeInit") != -1)
	{
		return CallLocalFunction("Streamer_OnGameModeInit", "");
	}
	return 1;
}

#if defined _ALS_OnGameModeInit
	#undef OnGameModeInit
#else
	#define _ALS_OnGameModeInit
#endif
#define OnGameModeInit Streamer_OnGameModeInit

forward
	Streamer_OnGameModeInit();

public
	OnPlayerConnect(playerid)
{
	Streamer_AddPlayer(playerid);
	if (Streamer_g_OPC)
	{
		return CallLocalFunction("Streamer_OnPlayerConnect", "d", playerid);
	}
	return 1;
}

#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect Streamer_OnPlayerConnect

forward
	Streamer_OnPlayerConnect(playerid);

public
	OnPlayerDisconnect(playerid, reason)
{
	Streamer_RemovePlayer(playerid);
	if (Streamer_g_OPDC)
	{
		return CallLocalFunction("Streamer_OnPlayerDisconnect", "dd", playerid, reason);
	}
	return 1;
}

#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect Streamer_OnPlayerDisconnect

forward
	Streamer_OnPlayerDisconnect(playerid, reason);

public
	OnPlayerPickUpPickup(playerid, pickupid)
{
	Streamer_CheckPickup(playerid, pickupid);
	if (Streamer_g_OPPP)
	{
		return CallLocalFunction("Streamer_OnPlayerPickUpPickup", "dd", playerid, pickupid);
	}
	return 1;
}

#if defined _ALS_OnPlayerPickUpPickup
	#undef OnPlayerPickUpPickup
#else
	#define _ALS_OnPlayerPickUpPickup
#endif
#define OnPlayerPickUpPickup Streamer_OnPlayerPickUpPickup

forward
	Streamer_OnPlayerPickUpPickup(playerid, pickupid);

// PAWN Invoke Section

forward
	Streamer_PublicFunction();

public
	Streamer_PublicFunction()
{
	new
		Float:value;
	CreatePickup(0, 0, 0.0, 0.0, 0.0, 0);
	CreatePlayer3DTextLabel(0, "", 0, 0.0, 0.0, 0.0, 0.0, 0, 0, 0);
	CreatePlayerObject(0, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
	DeletePlayer3DTextLabel(0, PlayerText3D:0);
	DestroyPickup(0);
	DestroyPlayerObject(0, 0);
	DisablePlayerCheckpoint(0);
	DisablePlayerRaceCheckpoint(0);
	GetPlayerInterior(0);
	GetPlayerObjectPos(0, 0, value, value, value);
	GetPlayerObjectRot(0, 0, value, value, value);
	GetPlayerPos(0, value, value, value);
	GetPlayerState(0);
	GetPlayerVirtualWorld(0);
	GetVehiclePos(0, value, value, value);
	MovePlayerObject(0, 0, 0.0, 0.0, 0.0, 0.0);
	RemovePlayerMapIcon(0, 0);
	SetPlayerCheckpoint(0, 0.0, 0.0, 0.0, 0.0);
	SetPlayerMapIcon(0, 0, 0.0, 0.0, 0.0, 0, 0);
	SetPlayerObjectPos(0, 0, 0.0, 0.0, 0.0);
	SetPlayerObjectRot(0, 0, 0.0, 0.0, 0.0);
	SetPlayerRaceCheckpoint(0, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
	StopPlayerObject(0, 0);
	UpdatePlayer3DTextLabelText(0, PlayerText3D:0, 0, "");
	return 1;
}