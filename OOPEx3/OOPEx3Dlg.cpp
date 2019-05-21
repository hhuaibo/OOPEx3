
// OOPEx3Dlg.cpp: 实现文件
//

#include "stdafx.h"
#include "OOPEx3.h"
#include "OOPEx3Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// COOPEx3Dlg 对话框



void COOPEx3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_GRADE, m_Grade);
	DDX_Text(pDX, IDC_EDIT_ID, m_ID);
	DDX_Control(pDX, IDC_LIST_LOG, m_Log);
	DDX_Control(pDX, IDC_LIST_CTRL, m_Inquiry);
	DDX_Text(pDX, IDC_EDIT_NAME, m_Name);
	DDX_Control(pDX, IDC_TREE, m_TreeCon);
	DDX_Text(pDX, IDC_EDIT_SUB1, m_Sub1);
	DDX_Text(pDX, IDC_EDIT_SUB2, m_Sub2);
	DDX_Text(pDX, IDC_EDIT_SUB3, m_Sub3);
}

BEGIN_MESSAGE_MAP(COOPEx3Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_ADD, &COOPEx3Dlg::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_RESET, &COOPEx3Dlg::OnBnClickedButtonReset)
	ON_NOTIFY(NM_DBLCLK, IDC_TREE, &COOPEx3Dlg::OnNMDblclkTree)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &COOPEx3Dlg::OnBnClickedButtonClear)
END_MESSAGE_MAP()


// COOPEx3Dlg 消息处理程序

BOOL COOPEx3Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	this->m_TreeCon.ModifyStyle(0, TVS_HASBUTTONS | TVS_HASLINES | TVS_LINESATROOT);
	root = this->m_TreeCon.InsertItem(_T("年级"));
	root1 = this->m_TreeCon.InsertItem(_T("一年级"), root);
	root2 = this->m_TreeCon.InsertItem(_T("二年级"), root);
	root3 = this->m_TreeCon.InsertItem(_T("三年级"), root);

	m_Inquiry.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_ONECLICKACTIVATE);
	m_Inquiry.InsertColumn(0, _T("姓名"), LVCFMT_LEFT, 80);
	m_Inquiry.InsertColumn(1, _T("学号"), LVCFMT_LEFT, 80);
	m_Inquiry.InsertColumn(2, _T("年级"), LVCFMT_LEFT, 80);
	m_Inquiry.InsertColumn(3, _T("Sub1"), LVCFMT_LEFT, 72);
	m_Inquiry.InsertColumn(4, _T("Sub2"), LVCFMT_LEFT, 72);
	m_Inquiry.InsertColumn(5, _T("Sub3"), LVCFMT_LEFT, 72);
	m_Inquiry.InsertColumn(6, _T("均分"), LVCFMT_LEFT, 72);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void COOPEx3Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void COOPEx3Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR COOPEx3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

/***********************************************************************************************************************
 * @Author: Huaibo
 * @Date:   2019-5-20
 ***********************************************************************************************************************/

//展开所有树形结点
void COOPEx3Dlg::MyExpandTree(HTREEITEM hTreeItem)
{
	if (!m_TreeCon.ItemHasChildren(hTreeItem))//如果树控件根节点没有子节点则返回
		return;

	HTREEITEM hNextItem = m_TreeCon.GetChildItem(hTreeItem);//若树控件的根节点有子节点则获取根节点的子节点
	while (hNextItem != NULL) {
		MyExpandTree(hNextItem);//递归，展开子节点下的所有子节点
		hNextItem = m_TreeCon.GetNextItem(hNextItem, TVGN_NEXT);//获取根节点的下一个子节点
	}
	m_TreeCon.Expand(hTreeItem, TVE_EXPAND);//展开节点
}

//向右侧的List Control添加学生信息数据
void COOPEx3Dlg::AddInquiry(CString name, CString id, CString garde)
{
	Student stu;
	CString str;

	if (FindListByID(name, id, garde, stu)) {
		m_Inquiry.InsertItem(counts, _T(""));
		m_Inquiry.SetItemText(counts, 0, stu.name);
		m_Inquiry.SetItemText(counts, 1, stu.ID);
		m_Inquiry.SetItemText(counts, 2, stu.grade);

		double avr = (stu.sub1 + stu.sub2 + stu.sub3) / 3.0;
		str.Format(_T("%.1lf"), stu.sub1);
		m_Inquiry.SetItemText(counts, 3, str);
		str.Format(_T("%.1lf"), stu.sub2);
		m_Inquiry.SetItemText(counts, 4, str);
		str.Format(_T("%.1lf"), stu.sub3);
		m_Inquiry.SetItemText(counts, 5, str);
		str.Format(_T("%.1lf"), avr);
		m_Inquiry.SetItemText(counts, 6, str);
	}

	return;
}

//打印日志
void COOPEx3Dlg::ShowLog(CString log)
{
	m_Log.AddString(log);
}

//查找学生信息并返回
bool COOPEx3Dlg::FindListByID(CString name, CString id, CString grade, Student & stu)
{
	std::list<Student>::iterator iter;
	for (iter = m_data.begin(); iter != m_data.end(); iter++) {
		if ((*iter).name == name && (*iter).ID == id && (*iter).grade == grade) {
			stu = *iter;
			return true;
		}
	}
	return false;
}

//查找学生是否录入
bool COOPEx3Dlg::FindListByID(CString name, CString id, CString grade)
{
	std::list<Student>::iterator iter;
	for (iter = m_data.begin(); iter != m_data.end(); iter++) {
		if ((*iter).ID == id && (*iter).grade == grade) {
			if ((*iter).name != name)
				MessageBox(_T("已录入相同ID学生信息"), _T("错误"));
			return true;
		}
	}
	return false;
}

//查找List Control已存在的ID
bool COOPEx3Dlg::FindListCtrlById(CString name, CString id, CString grade)
{
	CString nameText, idText, gradeText;
	for (int i = 0; i < counts; i++) {
		nameText = m_Inquiry.GetItemText(i, 0);
		idText = m_Inquiry.GetItemText(i, 1);
		gradeText = m_Inquiry.GetItemText(i, 2);
		
		if (nameText == name && idText == id && gradeText == grade) {
			return true;
		}
	}
	return false;
}

//添加学生信息
void COOPEx3Dlg::OnBnClickedButtonAdd()
{
	CString gradeText;
	if (m_Grade.GetCurSel() != -1) {
		m_Grade.GetLBText(m_Grade.GetCurSel(), gradeText);
	}
	UpdateData(TRUE);

	if (gradeText == _T("") || m_Name == _T("") || m_ID == _T("")) {
		MessageBox(_T("请填写完整数据"), _T("错误"));
	}
	else if (!FindListByID(m_Name, m_ID, gradeText)) {
		if (gradeText == _T("一年级")) {
			this->m_TreeCon.InsertItem(m_Name + _T(",") + m_ID, root1);
		}
		else if (gradeText == _T("二年级")) {
			this->m_TreeCon.InsertItem(m_Name + _T(",") + m_ID, root2);
		}
		else {
			this->m_TreeCon.InsertItem(m_Name + _T(",") + m_ID, root3);
		}

		Student stu(m_Name, m_ID, gradeText, m_Sub1, m_Sub2, m_Sub3);
		m_data.push_back(stu);
		ShowLog(_T("[Add]：添加学生 ") + m_Name + _T(",") + m_ID);
	}
	else
	{
		ShowLog(_T("[Add]：学生 ") + m_Name + _T(",") + m_ID + _T(" 已存在"));
	}
	MyExpandTree(root);
	
}

//重置编辑框
void COOPEx3Dlg::OnBnClickedButtonReset()
{
	m_Grade.SetCurSel(-1);
	m_Name = _T("");
	m_ID = _T("");
	m_Sub1 = 0.0;
	m_Sub2 = 0.0;
	m_Sub3 = 0.0;
	UpdateData(FALSE);
	ShowLog(_T("[Reset]：已为用户重置输入框 "));
}

//树形框双击事件
void COOPEx3Dlg::OnNMDblclkTree(NMHDR *pNMHDR, LRESULT *pResult)
{
	CString str, nameText, gradeText, idText;
	HTREEITEM hCurrentItem = m_TreeCon.GetSelectedItem();
	HTREEITEM pItem = m_TreeCon.GetParentItem(hCurrentItem);

	gradeText = m_TreeCon.GetItemText(pItem);
	str = m_TreeCon.GetItemText(hCurrentItem);
	nameText = str.Left(str.Find(_T(",")));
	idText = str.Right(str.GetLength() - str.Find(_T(",")) - 1);

	if (!FindListCtrlById(nameText, idText, gradeText)) {
		AddInquiry(nameText, idText, gradeText);
		ShowLog(_T("[Tree Control]：添加学生 ") + nameText + _T(" 到表格中"));
		++counts;
	}
	else {
		ShowLog(_T("[Tree Control]：学生 ") + nameText + _T(" 已添加到表格中"));
	}

	*pResult = 0;
}

//清空日志
void COOPEx3Dlg::OnBnClickedButtonClear()
{
	m_Log.ResetContent();
	ShowLog(_T("[Clear]：日志已清空"));
}