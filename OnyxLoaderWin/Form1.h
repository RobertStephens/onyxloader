#pragma once

#include "doflash.h"
#include <wininet.h>
#pragma comment(lib, "wininet.lib")

namespace TryUSB
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	using namespace System::Text;
	using namespace System::Globalization;

//	const UInt32 FT_LIST_NUMBER_ONLY = 0x80000000;
//	const UInt32 FT_LIST_BY_INDEX	= 0x40000000;
//	const UInt32 FT_LIST_ALL			= 0x20000000;
//	const UInt32 FT_OPEN_BY_SERIAL_NUMBER = 1;
//	const UInt32 FT_OPEN_BY_DESCRIPTION    = 2;

//	const UInt32 FT_EVENT_RXCHAR		= 1;
//	const UInt32 FT_EVENT_MODEM_STATUS  = 2;

#define FT_PREFIX [DllImport("FTD2XX.dll")]

enum {
    FT_OK,
    FT_INVALID_HANDLE,
    FT_DEVICE_NOT_FOUND,
    FT_DEVICE_NOT_OPENED,
    FT_IO_ERROR,
    FT_INSUFFICIENT_RESOURCES,
    FT_INVALID_PARAMETER,
    FT_INVALID_BAUD_RATE,

    FT_DEVICE_NOT_OPENED_FOR_ERASE,
    FT_DEVICE_NOT_OPENED_FOR_WRITE,
    FT_FAILED_TO_WRITE_DEVICE,
    FT_EEPROM_READ_FAILED,
    FT_EEPROM_WRITE_FAILED,
    FT_EEPROM_ERASE_FAILED,
	FT_EEPROM_NOT_PRESENT,
	FT_EEPROM_NOT_PROGRAMMED,
	FT_INVALID_ARGS,
	FT_NOT_SUPPORTED,
	FT_OTHER_ERROR
};

	typedef void * FT_HANDLE;
	typedef unsigned long DWORD;
	typedef unsigned long FT_STATUS;
	typedef void * LPVOID;
	typedef void * PVOID;
	typedef DWORD * LPDWORD;
	typedef DWORD ULONG;
	typedef unsigned short USHORT;
	typedef unsigned char UCHAR;
	typedef unsigned short WORD;
	typedef WORD * LPWORD;
	typedef unsigned char UCHAR;
	typedef UCHAR * PUCHAR;
	typedef char CHAR;
	typedef CHAR * PCHAR;
	typedef ULONG FT_DEVICE;
	typedef void *HANDLE;
	typedef int BOOL;
	#define FALSE   0
	#define TRUE    1
	// as c++. net is a managed application and our ftd2xx.dll is unmanaged code you must declare the functions here explicitly
	// to allow you to call them within the application. An include file and the .lib file simply wont work with c++.net. Its
	// a similar problem in c#.
	// see http://www.codeguru.com/Cpp/COM-Tech/complus/managed/article.php/c3947/ for more on this.
	// I have only included these 4 functions in this to show you how to do this. For other functions that you require similar
	// declerations will need to go here. 
 
	using namespace System::Runtime::InteropServices;
	FT_PREFIX FT_STATUS FT_Open(int deviceNumber, FT_HANDLE * pHandle);
	FT_PREFIX FT_STATUS FT_OpenEx(PVOID pArg1, DWORD Flags, FT_HANDLE *pHandle);
	FT_PREFIX FT_STATUS FT_ListDevices(PVOID pArg1, PVOID pArg2, DWORD Flags);
	FT_PREFIX FT_STATUS FT_ListDevices(UInt32 pvArg1, void * pvArg2, UInt32 dwFlags);	// FT_ListDevcies by serial number or description by index only
	FT_PREFIX FT_STATUS FT_Close(FT_HANDLE ftHandle);
	FT_PREFIX FT_STATUS FT_Read(FT_HANDLE ftHandle, LPVOID lpBuffer, DWORD nBufferSize, LPDWORD lpBytesReturned);
	FT_PREFIX FT_STATUS FT_Write(FT_HANDLE ftHandle, LPVOID lpBuffer, DWORD nBufferSize, LPDWORD lpBytesWritten);
	FT_PREFIX FT_STATUS FT_SetBaudRate(FT_HANDLE ftHandle,	ULONG BaudRate);
	FT_PREFIX FT_STATUS FT_SetDivisor(FT_HANDLE ftHandle,USHORT Divisor);
	FT_PREFIX FT_STATUS FT_SetDataCharacteristics(FT_HANDLE ftHandle, UCHAR WordLength, UCHAR StopBits, UCHAR Parity);
	FT_PREFIX FT_STATUS FT_SetFlowControl(FT_HANDLE ftHandle, USHORT FlowControl, UCHAR XonChar, UCHAR XoffChar	);
	FT_PREFIX FT_STATUS FT_ResetDevice(FT_HANDLE ftHandle);
	FT_PREFIX FT_STATUS FT_SetDtr(FT_HANDLE ftHandle);
	FT_PREFIX FT_STATUS FT_ClrDtr(FT_HANDLE ftHandle);
	FT_PREFIX FT_STATUS FT_SetRts(FT_HANDLE ftHandle);
	FT_PREFIX FT_STATUS FT_ClrRts(FT_HANDLE ftHandle);
	FT_PREFIX FT_STATUS FT_GetModemStatus(FT_HANDLE ftHandle,	ULONG *pModemStatus);
	FT_PREFIX FT_STATUS FT_SetChars(FT_HANDLE ftHandle, UCHAR EventChar, UCHAR EventCharEnabled, UCHAR ErrorChar, UCHAR ErrorCharEnabled);
	FT_PREFIX FT_STATUS FT_Purge(FT_HANDLE ftHandle, ULONG Mask);
	FT_PREFIX FT_STATUS FT_SetTimeouts(FT_HANDLE ftHandle,	ULONG ReadTimeout,	ULONG WriteTimeout);
	FT_PREFIX FT_STATUS FT_GetQueueStatus(FT_HANDLE ftHandle, DWORD *dwRxBytes);
	FT_PREFIX FT_STATUS FT_SetEventNotification(FT_HANDLE ftHandle, DWORD Mask,	PVOID Param	);
	FT_PREFIX FT_STATUS FT_GetStatus(FT_HANDLE ftHandle, DWORD *dwRxBytes, DWORD *dwTxBytes, DWORD *dwEventDWord);
	FT_PREFIX FT_STATUS FT_SetBreakOn(FT_HANDLE ftHandle);
	FT_PREFIX FT_STATUS FT_SetBreakOff(FT_HANDLE ftHandle);	
	FT_PREFIX FT_STATUS FT_SetWaitMask(FT_HANDLE ftHandle, DWORD Mask);
	FT_PREFIX FT_STATUS FT_WaitOnMask(FT_HANDLE ftHandle, DWORD *Mask);
	FT_PREFIX FT_STATUS FT_GetEventStatus(FT_HANDLE ftHandle, DWORD *dwEventDWord);
	FT_PREFIX FT_STATUS FT_ReadEE(FT_HANDLE ftHandle, DWORD dwWordOffset, LPWORD lpwValu);
	FT_PREFIX FT_STATUS FT_WriteEE(FT_HANDLE ftHandle,	DWORD dwWordOffset, WORD wValue);
	FT_PREFIX FT_STATUS FT_EraseEE(FT_HANDLE ftHandle);
// Missed out the programming stuff +++ 

	FT_PREFIX FT_STATUS  FT_EE_UASize(FT_HANDLE ftHandle, LPDWORD lpdwSize);
	FT_PREFIX FT_STATUS  FT_EE_UAWrite(FT_HANDLE ftHandle, PUCHAR pucData, DWORD dwDataLen	);
	FT_PREFIX FT_STATUS  FT_EE_UARead(FT_HANDLE ftHandle, PUCHAR pucData, DWORD dwDataLen, LPDWORD lpdwBytesRead);
	FT_PREFIX FT_STATUS  FT_SetLatencyTimer(FT_HANDLE ftHandle, UCHAR ucLatency);
	FT_PREFIX FT_STATUS  FT_GetLatencyTimer(FT_HANDLE ftHandle, PUCHAR pucLatency);
	FT_PREFIX FT_STATUS  FT_SetBitMode(FT_HANDLE ftHandle, UCHAR ucMask, UCHAR ucEnable);
	FT_PREFIX FT_STATUS  FT_GetBitMode(FT_HANDLE ftHandle, PUCHAR pucMode);
	FT_PREFIX FT_STATUS  FT_SetUSBParameters(FT_HANDLE ftHandle, ULONG ulInTransferSize, ULONG ulOutTransferSize);
	FT_PREFIX FT_STATUS  FT_GetDeviceInfo(FT_HANDLE ftHandle, FT_DEVICE *lpftDevice, LPDWORD lpdwID, PCHAR SerialNumber, PCHAR Description,	LPVOID Dummy);
	FT_PREFIX FT_STATUS  FT_StopInTask(FT_HANDLE ftHandle);
	FT_PREFIX FT_STATUS  FT_RestartInTask(FT_HANDLE ftHandle);
	FT_PREFIX FT_STATUS  FT_SetResetPipeRetryCount(FT_HANDLE ftHandle, DWORD dwCount);
	FT_PREFIX FT_STATUS  FT_ResetPort(FT_HANDLE ftHandle);

	// need these kernel functions for the Event Handling stuff
	[DllImport("Kernel32.dll")] DWORD WaitForSingleObject(HANDLE hHandle,  DWORD dwMilliseconds);
	[DllImport("Kernel32.dll")] HANDLE CreateEvent(void * pNULL, BOOL bManualReset, BOOL bInitialState, char * pcNULL);
	[DllImport("Kernel32.dll")] BOOL SetEvent(HANDLE hEvent);
// missed out the W32 stuff as well

	FT_HANDLE handle;
	HANDLE hEvent;
	/// <summary> 
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the 
	///          'Resource File Name' property for the managed resource compiler tool 
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public __gc class Form1 : public System::Windows::Forms::Form
	{	
	public:
		Form1(void)
		{
			InitializeComponent();
		}

	private:
		void ReadingProc()
        {
			ArrayList * palReadData;
			palReadData = new ArrayList();
			TimeSpan waitTime = TimeSpan(0, 0, 1);	// 1 second timeout
			static char c = 0;
			char* pstr6 = &c;
			FT_STATUS status;

			while(bContinue) {
				DWORD dwRead, dwRXBytes;
				Byte b;
				NumberFormatInfo*   provider = new NumberFormatInfo( );

				WaitForSingleObject(hEvent, -1);
				if(handle) {
					status = FT_GetQueueStatus(handle, &dwRead);
					if(status != FT_OK) {
						MessageBox::Show("GError");
						continue;
					}
					while(dwRead && bContinue) {
						status = FT_Read(handle, &b, 1, &dwRXBytes);
						if(status != FT_OK) {
							MessageBox::Show("RError");
							continue;
						}
						else {
					//		String* s;
					//		s = Convert::ToString(b);
					//		listBox1->Items->Add(s);
						}
						status = FT_GetQueueStatus(handle, &dwRead);
					}
				}
				Thread::Sleep(0);
			}
			if(handle) {
				FT_Close(handle);
			}
        }
  
	protected:
		void Dispose(Boolean disposing)
		{
			StopThread();		// Close our thread

			if (disposing && components)
			{
				components->Dispose();
			}
			__super::Dispose(disposing);
		}

	private: System::Windows::Forms::Button *  btnClose;
	private: System::Windows::Forms::Button *  btnSend;
	private: System::Threading::Thread * thrdReader;







	private: bool bContinue;
	private: UInt32 dwOpenFlags;
	private: ManualResetEvent * ev;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container * components;

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnClose = (new System::Windows::Forms::Button());
			this->btnSend = (new System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnClose
			// 
			this->btnClose->Location = System::Drawing::Point(12, 12);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(115, 23);
			this->btnClose->TabIndex = 1;
			this->btnClose->Text = L"Upload Log";
			this->btnClose->Click += new System::EventHandler(this, &Form1::ButtonCancel_Click);
			// 
			// btnSend
			// 
			this->btnSend->Location = System::Drawing::Point(137, 12);
			this->btnSend->Name = L"btnSend";
			this->btnSend->Size = System::Drawing::Size(138, 23);
			this->btnSend->TabIndex = 2;
			this->btnSend->Text = L"Update Firmware";
			this->btnSend->Click += new System::EventHandler(this, &Form1::btnSend_Click);
			// 
			// Form1
			// 
			this->AutoScaleBaseSize = System::Drawing::Size(5, 13);
			this->ClientSize = System::Drawing::Size(287, 48);
			this->Controls->Add(this->btnSend);
			this->Controls->Add(this->btnClose);
			this->Location = System::Drawing::Point(56, 48);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(303, 86);
			this->MinimumSize = System::Drawing::Size(303, 86);
			this->Name = L"Form1";
			this->Text = L"OnyxLoader";
			this->Load += new System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);

		}	

	private: System::Void ButtonCancel_Click(System::Object *  sender, System::EventArgs *  e)
			{
				printf("Sending log\n");

				char *data = do_get_log();
				char *boundary = "0xKhTmLbOuNdArY";

				char *buffer = (char*) malloc (sizeof(char)*strlen(data) + 2048);
				char *hdrs   = (char*) malloc(2048);

			    //print header
			    sprintf(hdrs,"Content-Type: multipart/form-data; boundary=%s\r\n",boundary);
				sprintf(buffer,"--%s\r\n",boundary);
			    sprintf(buffer+strlen(buffer),"Content-Disposition: form-data; name=\"uploadedfile\"; filename=\"sc2\"\r\n");
				sprintf(buffer+strlen(buffer),"Content-Type: application/octet-stream\r\n\r\n");

			    sprintf(buffer+strlen(buffer),"%s\r\n",data);
			    sprintf(buffer+strlen(buffer),"--%s--\r\n",boundary);


				HINTERNET hSession = InternetOpen("WinSock",INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);

			    HINTERNET hConnect = InternetConnect(hSession, "41j.com",INTERNET_DEFAULT_HTTP_PORT, NULL, NULL, INTERNET_SERVICE_HTTP, 0, 1);

			    HINTERNET hRequest = HttpOpenRequest(hConnect, (const char*)"POST","sc/sc.php", NULL, NULL, (const char**)"*/*\0", 0, 1);

			    BOOL sent= HttpSendRequest(hRequest, hdrs, strlen(hdrs), buffer, strlen(buffer));
			 
			    //close any valid internet-handles
			    InternetCloseHandle(hSession);
			    InternetCloseHandle(hConnect);
			    InternetCloseHandle(hRequest);

			}
	private: System::Void OpenPort()
			 {
				FT_STATUS ftStatus = FT_OK;
				ftStatus = FT_Open(0, &handle);
			 }

 	private: System::Void ClosePort()
			 {
				if(handle) {
					FT_Close(handle);
					handle = NULL;
				}
			 }
	private: System::Void btnSend_Click(System::Object *  sender, System::EventArgs *  e)
			 {
				
    
    // Download flash image from http://41j.com/safecast_latest.bin

	HINTERNET hOpen = InternetOpen("WinSock",INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);


    char *szUrl = "http://41j.com/safecast_latest.bin"; // URL
    
	HANDLE hFile     = INVALID_HANDLE_VALUE;
    HANDLE hTempFile = INVALID_HANDLE_VALUE; 

    BOOL fSuccess  = FALSE;
    DWORD dwRetVal = 0;
    UINT uRetVal   = 0;

    DWORD dwBytesRead    = 0;
    DWORD dwBytesWritten = 0; 

    char szFileName[MAX_PATH];  
    TCHAR lpTempPathBuffer[MAX_PATH];
    char  chBuffer[1024]; 


	// create temp file, the windows way
	     //  Gets the temp path env string (no guarantee it's a valid path).
    dwRetVal = GetTempPath(MAX_PATH,          // length of the buffer
                           lpTempPathBuffer); // buffer for path 

    //  Generates a temporary file name. 
    uRetVal = GetTempFileName(lpTempPathBuffer, // directory for tmp files
                              TEXT("DEMO"),     // temp file name prefix 
                              0,                // create unique name 
                              szFileName);      // buffer for name
	
       DWORD dwSize;
       CHAR   szHead[] = "Accept: */*\r\n\r\n";
       VOID * szTemp[25];
       HINTERNET  hConnect;
      FILE * pFile;

       if ( !(hConnect = InternetOpenUrl ( hOpen, szUrl, szHead,
             lstrlen (szHead), INTERNET_FLAG_DONT_CACHE, 0)))
       {
       //  cerr << "Error !" << endl;
           return ;
       }

       if  ( !(pFile = fopen (szFileName, "wb" ) ) )
      {
        //   cerr << "Error !" << endl;
          return ;
      }
       do
       {
          // Keep coping in 25 bytes chunks, while file has any data left.
          // Note: bigger buffer will greatly improve performance.
          if (!InternetReadFile (hConnect, szTemp, 50,  &dwSize) )
          {
              fclose (pFile);
         //    cerr << "Error !" << endl;
            return ;
          }
          if (!dwSize)
              break;  // Condition of dwSize=0 indicate EOF. Stop.
          else
             fwrite(szTemp, sizeof (char), dwSize , pFile);
       }   // do
      while (TRUE);
      fflush (pFile);
      fclose (pFile);


    // Flash    
    int argc=3;
    char *argv[3];
    char *argv0 = szFileName;
    char *argv1 = "-f";
    char *argv2 = (char *) szFileName;
    argv[0] = argv0;
    argv[1] = argv1;
    argv[2] = argv2;
    
    int result = do_flash_main(argc,argv);


			 }

private: System::Void FillComboBox(UInt32 dwDescFlags)
	{
	
	}
private: System::Void StopThread()
		 {
			bContinue = false;
			if(hEvent)		// let the thread come out of waiting for infinite time
				SetEvent(hEvent);
			if(thrdReader && thrdReader->IsAlive) {	// stop it
			 	TimeSpan waitTime = TimeSpan(0, 0, 1);	// 1 second timeout
				if(thrdReader->Join(waitTime) != true) {
					thrdReader->Abort();	// didnt stop the thread - take more drastic action
				}
			}
		 }

private: System::Void StartThread()
		 {
			 // Create a reader thread here
			thrdReader = new Thread(new ThreadStart(this, &TryUSB::Form1::ReadingProc));
			bContinue = true;
			thrdReader->Start();
			while (!thrdReader->IsAlive);	// wait for the thread to start
			Thread::Sleep(1000);
		 }

private: System::Void Form1_Load(System::Object *  sender, System::EventArgs *  e)
		{	
			handle = NULL;
			hEvent = CreateEvent(NULL, FALSE, FALSE, "");
	
		}

private: System::Void comboBox1_SelectedIndexChanged(System::Object *  sender, System::EventArgs *  e)
		{
			ClosePort();			 
			OpenPort();
		}

private: System::Void radioNumber_CheckedChanged(System::Object *  sender, System::EventArgs *  e)
		 {

		 }

private: System::Void radioDescription_CheckedChanged(System::Object *  sender, System::EventArgs *  e)
		 {

		 }

private: System::Void radioSerial_CheckedChanged(System::Object *  sender, System::EventArgs *  e)
		 {

		 }
};
}


