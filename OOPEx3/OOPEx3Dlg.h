
// OOPEx3Dlg.h: 头文件
//
#include "Student.h"
#include <list>
#pragma once


// COOPEx3Dlg 对话框
class COOPEx3Dlg : public CDialogEx
{
// 构造
public:
	COOPEx3Dlg(CWnd* pParent = nullptr)
		: CDialogEx(IDD_OOPEX3_DIALOG, pParent)
		, m_ID(_T(""))
		, m_Name(_T(""))
		, m_Sub1(0)
		, m_Sub2(0)
		, m_Sub3(0)
	{
		m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
	}	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OOPEX3_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:
	int counts = 0; //记录List Control添加的学生个数
	HTREEITEM root, root1, root2, root3;
	std::list<Student> m_data;

	bool FindListByID(CString name, CString id, CString grade, Student& stu);
	bool FindListByID(CString name, CString id, CString grade);
	bool FindListCtrlById(CString name, CString id, CString grade);
	
	void MyExpandTree(HTREEITEM hTreeItem);
	void AddInquiry(CString name, CString id, CString garde);
	void ShowLog(CString log);
	
public:
	CString m_Name = _T("");
	CString m_ID = _T("");

	CComboBox m_Grade;
	CListBox m_Log;
	CListCtrl m_Inquiry;
	CTreeCtrl m_TreeCon;

	double m_Sub1 = 0.0;
	double m_Sub2 = 0.0;
	double m_Sub3 = 0.0;

	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnBnClickedButtonReset();
	afx_msg void OnNMDblclkTree(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButtonClear();
};
