#pragma once

#include <windows.h>
#include <string>


class C_DllPathData
{
protected:
	C_DllPathData(HINSTANCE i_hDllHandle);
	~C_DllPathData(void);

private:
	C_DllPathData(const C_DllPathData&);
	C_DllPathData& operator=(const C_DllPathData&);

public:
	//Cr�er une instance unique de C_DllPathData
	//Le handle n'est � renseigner que la premi�re fois dans le DLL_PROCESS_ATTACH
	static C_DllPathData& createInstance(HINSTANCE i_hDllHandle = NULL);

public:
	//R�cup�re le path de la DLL
	//Ex : "C:\DllPath\"
	const std::string& getDllPath() const;
	//R�cup�re le nom de la DLL
	//Ex : "MaDll.dll"
	const std::string& getDllFilename() const;
	//R�cup�re la racine de la DLL
	//Ex : "C:"
	const std::string& getDllDrive() const;
	//R�cup�re le path de l'EXE
	//Ex : "C:\ExePath\"
	const std::string& getExePath() const;
	//R�cup�re le nom de l'EXE
	//Ex : "MonAppli.exe"
	const std::string& getExeFilename() const;

	//Cr�er un path complet relatif � l'emplacement de la DLL :
	// - � partir d'un path quelconque (l_bIsPath � true)
	// - � partir d'un nom de fichier ou path+nom de fichier quelconque (l_bIsPath � false)
	std::string computePath(const std::string& l_sPathToCompute, const bool l_bIsPath = true);
	//Extrait le nom de fichier � partir du nom avec extension
	//"myFile.ext" --> "myFile"
	//"myFile" --> "myFile"
	static std::string getName(const std::string& i_sFilename);
	//Extrait l'extension de fchier � partir du nom avec extension
	//"myFile.ext" --> "ext"
	//"myFile" --> ""
	static std::string getExt(const std::string& i_sFilename);

protected:
	std::string m_sDllPath;
	std::string m_sDllFilename;
	std::string m_sDllDrive;
	std::string m_sExePath;
	std::string m_sExeFilename;
};
