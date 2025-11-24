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

#include "M2Emulator.h"
static int detectedGameId = 0;
static int WindowsLoop()
{
	/*INT_PTR data1 = helpers->ReadIntPtr(0x174CF0, true);
	Outputs->SetValue(OutputLampStart, !!(data1 & 0x04));
	Outputs->SetValue(OutputLampLeader, !!(data1 & 0x80));
	Outputs->SetValue(OutputLampView1, !!(data1 & 0x08));
	Outputs->SetValue(OutputLampView2, !!(data1 & 0x10));
	Outputs->SetValue(OutputLampView3, !!(data1 & 0x20));
	Outputs->SetValue(OutputLampView4, !!(data1 & 0x40));*/
	
	/*sega rally*/
	if ((detectedGameId == 1) || (detectedGameId == 14) || (detectedGameId == 15))
	{
		INT_PTR data1 = helpers->ReadIntPtr(0x174CF0, true);
		Outputs->SetValue(OutputLampStart, !!(data1 & 0x04));
		Outputs->SetValue(OutputLampLeader, !!(data1 & 0x80));
		Outputs->SetValue(OutputLampView1, !!(data1 & 0x08));
		Outputs->SetValue(OutputLampView2, !!(data1 & 0x10));
		Outputs->SetValue(OutputLampView3, !!(data1 & 0x20));
		Outputs->SetValue(OutputLampView4, !!(data1 & 0x40));
	}
	/*stcc*/
	else if ((detectedGameId == 4) || (detectedGameId == 18) || (detectedGameId == 19))
	{
		INT_PTR data2 = helpers->ReadIntPtr(0x174CF0, true);
		Outputs->SetValue(OutputLampStart, !!(data2 & 0x04));
		Outputs->SetValue(OutputLampLeader, !!(data2 & 0x80));
		Outputs->SetValue(OutputLampView1, !!(data2 & 0x08));
		Outputs->SetValue(OutputLampView2, !!(data2 & 0x10));
		Outputs->SetValue(OutputLampView3, !!(data2 & 0x20));
		Outputs->SetValue(OutputLampView4, !!(data2 & 0x40));
	}
	/*daytona*/
	else if ((detectedGameId == 2) || (detectedGameId == 7) || (detectedGameId == 8) || (detectedGameId == 9) || (detectedGameId == 10) || (detectedGameId == 11) || (detectedGameId == 12) || (detectedGameId == 13))
	{
		INT_PTR Rambase = helpers->ReadIntPtr(0x1AA888, true);
		INT_PTR RambaseA = helpers->ReadIntPtr(Rambase + 0x100, false);
		UINT8 data = helpers->ReadByte(RambaseA + 0x824, false);

		Outputs->SetValue(OutputLampStart, !!(data & 0x04));
		Outputs->SetValue(OutputLampLeader, !!(data & 0x80));
		Outputs->SetValue(OutputLampView1, !!(data & 0x08));
		Outputs->SetValue(OutputLampView2, !!(data & 0x10));
		Outputs->SetValue(OutputLampView3, !!(data & 0x20));
		Outputs->SetValue(OutputLampView4, !!(data & 0x40));
		Outputs->SetValue(OutputRawLamps, data);
	}
	/*indy500*/
	else if ((detectedGameId == 3) || (detectedGameId == 16) || (detectedGameId == 17))
	{
		INT_PTR data2 = helpers->ReadIntPtr(0x174CF0, true);
		Outputs->SetValue(OutputLampStart, !!(data2 & 0x04));
		Outputs->SetValue(OutputLampLeader, !!(data2 & 0x80));
		Outputs->SetValue(OutputLampView1, !!(data2 & 0x08));
		Outputs->SetValue(OutputLampView2, !!(data2 & 0x10));
		Outputs->SetValue(OutputLampView3, !!(data2 & 0x20));
		Outputs->SetValue(OutputLampView4, !!(data2 & 0x40));
	}
	/*overrev*/
	else if ((detectedGameId == 20) || (detectedGameId == 5))
	{
		INT_PTR data2 = helpers->ReadIntPtr(0x174CF0, true);
		Outputs->SetValue(OutputLampStart, !!(data2 & 0x04));
		Outputs->SetValue(OutputLampLeader, !!(data2 & 0x80));
		Outputs->SetValue(OutputLampView1, !!(data2 & 0x08));
		Outputs->SetValue(OutputLampView2, !!(data2 & 0x10));
		Outputs->SetValue(OutputLampView3, !!(data2 & 0x20));
		Outputs->SetValue(OutputLampView4, !!(data2 & 0x40));
	}
	/*supergt24*/
	else if (detectedGameId == 6)
	{
		INT_PTR data2 = helpers->ReadIntPtr(0x174CF0, true);
		Outputs->SetValue(OutputLampStart, !!(data2 & 0x04));
		Outputs->SetValue(OutputLampLeader, !!(data2 & 0x80));
		Outputs->SetValue(OutputLampView1, !!(data2 & 0x08));
		Outputs->SetValue(OutputLampView2, !!(data2 & 0x10));
		Outputs->SetValue(OutputLampView3, !!(data2 & 0x20));
		Outputs->SetValue(OutputLampView4, !!(data2 & 0x40));
	}
	else if ((detectedGameId == 21) || (detectedGameId == 22) || (detectedGameId == 23))
	{
		INT_PTR data = helpers->ReadIntPtr(0x174CF0, true);
		//INT_PTR drive = helpers->ReadIntPtr(0x174CF4, true);
		//INT_PTR RambaseA = helpers->ReadIntPtr(0x5AA8F0, false);
		//INT_PTR RambaseB = helpers->ReadIntPtr(0x5AA8F4, false);
		//UINT8 data1 = helpers->ReadByte(RambaseA + 0x420, false);
		//INT_PTR data2 = helpers->ReadIntPtr(RambaseB + 0x500, false);
		//UINT8 data3 = helpers->ReadByte(data2 + 0x578B64, false);

		Outputs->SetValue(OutputLampStart, !!(data & 0x04));
		Outputs->SetValue(OutputLampLeader, !!(data & 0x08));
		Outputs->SetValue(OutputLampView3, !!(data & 0x80));
		Outputs->SetValue(OutputLampView1, !!(data & 0x10));
		Outputs->SetValue(OutputLampView2, !!(data & 0x20));
		Outputs->SetValue(OutputLampView4, !!(data & 0x40));
		//Outputs->SetValue(OutputRawDrive, drive);
		//Outputs->SetValue(OutputSpeedo, data1);
		//Outputs->SetValue(OutputDash, data3);
	}
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

void M2Emulator::OutputsGameLoop()
{
	
	if (!init)
	{
		/*Outputs = new CWinOutputs();
		m_game.name = "M2 Emulator"; 
		Outputs->SetGame(m_game);
		Outputs->Initialize();
		Outputs->Attached();*/

		if (FindWindowA(0, ("Sega Rally Championship"))) detectedGameId = 1;
		else if (FindWindowA(0, ("Daytona USA")))  detectedGameId = 2;
		else if (FindWindowA(0, ("Indianapolis 500 (Rev A, Deluxe)")))  detectedGameId = 3;
		else if (FindWindowA(0, ("Sega Touring Car Championship (Rev A)")))  detectedGameId = 4;
		else if (FindWindowA(0, ("Over Rev")))  detectedGameId = 5;
		else if (FindWindowA(0, ("Super GT 24h")))  detectedGameId = 6;
		else if (FindWindowA(0, ("Daytona USA '93 Edition")))  detectedGameId = 7;
		else if (FindWindowA(0, ("Daytona USA (Saturn Ads)")))  detectedGameId = 8;
		else if (FindWindowA(0, ("Daytona USA Special Edition"))) detectedGameId = 9;
		else if (FindWindowA(0, ("Daytona USA Turbo")))  detectedGameId = 10;
		else if (FindWindowA(0, ("Daytona USA Turbo (Rev A)")))  detectedGameId = 11;
		else if (FindWindowA(0, ("Daytona USA: GTX 2004")))  detectedGameId = 12;
		else if (FindWindowA(0, ("Daytona USA: To The Maxx")))  detectedGameId = 13;
		else if (FindWindowA(0, ("Sega Rally Championship (Rev B)")))  detectedGameId = 14;
		else if (FindWindowA(0, ("Sega Rally Pro Drivin'")))  detectedGameId = 15;
		else if (FindWindowA(0, ("Indianapolis 500 (Rev A, Twin, Newer rev)")))  detectedGameId = 16;
		else if (FindWindowA(0, ("Indianapolis 500 (Rev A, Twin, Older rev)")))  detectedGameId = 17;
		else if (FindWindowA(0, ("Sega Touring Car Championship")))  detectedGameId = 18;
		else if (FindWindowA(0, ("Sega Touring Car Championship (Rev B)")))  detectedGameId = 19;
		else if (FindWindowA(0, ("Over Rev (Model 2B)")))  detectedGameId = 20;
		else if (FindWindowA(0, ("ManxTT Superbike (Rev C, Twin)")))  detectedGameId = 21;
		else if (FindWindowA(0, ("ManxTT Superbike (Rev D, Deluxe)")))  detectedGameId = 22;
		else if (FindWindowA(0, ("Motor Raid")))  detectedGameId = 23;

		
		if (detectedGameId == 1)
		{
			m_game.name = "Sega Rally Championship";
		}
		else if (detectedGameId == 2)
		{
			m_game.name = "Daytona USA";
		}
		else if (detectedGameId == 3)
		{
			m_game.name = "Indianapolis 500 (Rev A, Deluxe)";
		}
		else if (detectedGameId == 4)
		{
			m_game.name = "Sega Touring Car Championship (Rev A)";
		}
		else if (detectedGameId == 5)
		{
			m_game.name = "Over Rev";
		}
		else if (detectedGameId == 6)
		{
			m_game.name = "Super GT 24h";
		}
		else if (detectedGameId == 7)
		{
			m_game.name = "Daytona USA '93 Edition";
		}
		else if (detectedGameId == 8)
		{
			m_game.name = "Daytona USA (Saturn Ads)";
		}
		else if (detectedGameId == 9)
		{
			m_game.name = "Daytona USA Special Edition";
		}
		else if (detectedGameId == 10)
		{
			m_game.name = "Daytona USA Turbo";
		}
		else if (detectedGameId == 11)
		{
			m_game.name = "Daytona USA Turbo (Rev A)";
		}
		else if (detectedGameId == 12)
		{
			m_game.name = "Daytona USA: GTX 2004";
		}
		else if (detectedGameId == 13)
		{
			m_game.name = "Daytona USA: To The Maxx";
		}
		else if (detectedGameId == 14)
		{
			m_game.name = "Sega Rally Championship (Rev B)";
		}
		else if (detectedGameId == 15)
		{
			m_game.name = "Sega Rally Pro Drivin'";
		}
		else if (detectedGameId == 16)
		{
			m_game.name = "Indianapolis 500 (Rev A, Twin, Newer rev)";
		}
		else if (detectedGameId == 17)
		{
			m_game.name = "Indianapolis 500 (Rev A, Twin, Older rev)";
		}
		else if (detectedGameId == 18)
		{
			m_game.name = "Sega Touring Car Championship";
		}
		else if (detectedGameId == 19)
		{
			m_game.name = "Sega Touring Car Championship (Rev B)";
		}
		else if (detectedGameId == 20)
		{
			m_game.name = "Over Rev (Model 2B)";
		}
		else if (detectedGameId == 21)
		{
			m_game.name = "ManxTT Superbike (Rev C, Twin)";
		}
		else if (detectedGameId == 22)
		{
			m_game.name = "ManxTT Superbike (Rev D, Deluxe)";
		}
		else if (detectedGameId == 23)
		{
			m_game.name = "Motor Raid";
		}
		
		if (detectedGameId != 0)
		{
			Outputs = new CWinOutputs();
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
		else if(detectedGameId == 0)
		{
			init = false;
		}
	}
}