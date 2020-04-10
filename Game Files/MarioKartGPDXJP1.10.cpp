/*This file is part of Output Blaster.

Output Blaster is free software : you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Output Blaster is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Output Blaster.If not, see < https://www.gnu.org/licenses/>.*/

#include "MarioKartGPDXJP1.10.h"

static int WindowsLoop()
{
	imageBase = (uintptr_t)GetModuleHandleA(0);
	BYTE ButtonData = *(BYTE*)(imageBase + 0xA4528D);
	BYTE BillboardData = *(BYTE*)(imageBase + 0xA4694C);
	BYTE BillboardData2 = *(BYTE*)(imageBase + 0xA4694D);
	BYTE MonitorSideData = *(BYTE*)(imageBase + 0xA469C1);
	BYTE MonitorSideData2 = *(BYTE*)(imageBase + 0xA469C2);
	BYTE UnderLampData = *(BYTE*)(imageBase + 0xA452A6);
	BYTE UnderLampData2 = *(BYTE*)(imageBase + 0xA452A7);

	Outputs->SetValue(OutputItemButton, !!(ButtonData & 0x04));
	Outputs->SetValue(OutputMarioButton, !!(ButtonData & 0x08));
	Outputs->SetValue(OutputBillboardRed, !!(BillboardData & 0xF0));
	Outputs->SetValue(OutputBillboardGreen, !!(BillboardData & 0x0F));
	Outputs->SetValue(OutputBillboardBlue, !!(BillboardData2 & 0xF0));
	Outputs->SetValue(OutputBillboardWhite, !!(BillboardData2 & 0xFF));
	Outputs->SetValue(OutputSideRed, !!(MonitorSideData & 0xF0));
	Outputs->SetValue(OutputSideGreen, !!(MonitorSideData & 0x0F));
	Outputs->SetValue(OutputSideBlue, !!(MonitorSideData2 & 0xF0));
	Outputs->SetValue(OutputSideWhite, !!(MonitorSideData2 & 0xFF));
	Outputs->SetValue(OutputLampRed, !!(UnderLampData & 0xF0));
	Outputs->SetValue(OutputLampGreen, !!(UnderLampData & 0x0F));
	Outputs->SetValue(OutputLampBlue, !!(UnderLampData2 & 0xF0));
	Outputs->SetValue(OutputLampWhite, !!(UnderLampData2 & 0xFF));
	return 0;
}

static DWORD WINAPI OutputsAreGo(LPVOID lpParam)
{
	while (true)
	{
		WindowsLoop();
		Sleep(SleepA);
	}
}

void MarioKartGPDXJP110::OutputsGameLoop()
{
	if (!init)
	{
		Outputs = new CWinOutputs();
		m_game.name = "Mario Kart GP DX";
		Outputs->SetGame(m_game);
		Outputs->Initialize();
		Outputs->Attached();
		CreateThread(NULL, 0, OutputsAreGo, NULL, 0, NULL);
		while (GetMessage(&Msg1, NULL, NULL, 0))
		{
			TranslateMessage(&Msg1);
			DispatchMessage(&Msg1);
		}
		init = true;
	}
}