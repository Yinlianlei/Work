package sql

type Huawei_fid_info struct{
	Fid 		string `json:"fid" xorm:"pk unique"`
	Uid			string `json:"uid" xorm:"not null int(5)"`//学前标识符
	Id 			string `json:"id" xorm:"varchar(20)"`//学号-待定是什么学号？大学的还是其他的？
	Name 		string `json:"name" xorm:"not null varchar(20)"`//姓名
	University	string `json:"university" xorm:"not null varchar(20)"`//学校
	School		string `json:"school" xorm:"not null varchar(20)"`//学院
	Course		string `json:"course" xorm:"not null varchar(20)"`//课程
	Times		string `json:"times" xorm:"not null int "`//重修次数
}

type Huawei_evidence struct{
	Id string `json:"id" xorm:"pk unique"`
	Fid string	`json:"fid" xorm:"not null varchar(255)"`
	Evidence string `json:"evidence" xorm:"not null varchar(255)"`
	Info string `json:"info" xorm:"varchar(255)"`
}

type Huawei_grant2user struct{
	Id			int		`json:"id" xorm:"pk autoincr unique"`//编号
	Name 		string	`json:"name" xorm:"not null varchar(20)"`//姓名
	University	string	`json:"university" xorm:"not null varchar(20)"`//学校
    Age 		int		`json:"age" xorm:"not null varchar(20)"`//年龄
    Position 	string	`json:"position" xorm:"not null varchar(20)"`//职位
    Gra 		int		`json:"gra" xorm:"not null int"`//授权true/false
}