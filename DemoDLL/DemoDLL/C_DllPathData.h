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
	//Créer une instance unique de C_DllPathData
	//Le handle n'est à renseigner que la première fois dans le DLL_PROCESS_ATTACH
	static C_DllPathData& createInstance(HINSTANCE i_hDllHandle = NULL);

public:
	//Récupère le path de la DLL
	//Ex : "C:\DllPath\"
	const std::string& getDllPath() const;
	//Récupère le nom de la DLL
	//Ex : "MaDll.dll"
	const std::string& getDllFilename() const;
	//Récupère la racine de la DLL
	//Ex : "C:"
	const std::string& getDllDrive() const;
	//Récupère le path de l'EXE
	//Ex : "C:\ExePath\"
	const std::string& getExePath() const;
	//Récupère le nom de l'EXE
	//Ex : "MonAppli.exe"
	const std::string& getExeFilename() const;

	//Créer un path complet relatif à l'emplacement de la DLL :
	// - à partir d'un path quelconque (l_bIsPath à true)
	// - à partir d'un nom de fichier ou path+nom de fichier quelconque (l_bIsPath à false)
	std::string computePath(const std::string& l_sPathToCompute, const bool l_bIsPath = true);
	//Extrait le nom de fichier à partir du nom avec extension
	//"myFile.ext" --> "myFile"
	//"myFile" --> "myFile"
	static std::string getName(const std::string& i_sFilename);
	//Extrait l'extension de fchier à partir du nom avec extension
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
