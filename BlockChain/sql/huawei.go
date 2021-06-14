package sql

type Huawei_fid_info struct{
	Fid 		string `json:"fid" xorm:"pk unique"`
	Uid			int `json:"uid" xorm:"not null int"`//学前标识符
	Id 			string `json:"id" xorm:"varchar(20)"`//学号-待定是什么学号？大学的还是其他的？
	Name 		string `json:"name" xorm:"not null varchar(20)"`//姓名
	University	string `json:"university" xorm:"not null varchar(20)"`//学校
	School		string `json:"school" xorm:"not null varchar(20)"`//学院
	Course		string `json:"course" xorm:"not null varchar(20)"`//课程
	Times		int `json:"times" xorm:"not null int "`//重修次数
}

type Huawei_evidence struct{
	Id string `json:"id" xorm:"pk unique"`
	Fid string	`json:"fid" xorm:"not null varchar(255)"`
	Evidence string `json:"evidence" xorm:"not null varchar(255)"`
	Info string `json:"info" xorm:"varchar(255)"`
}

type Huawei_grant2user struct{
	Id			int		`json:"id" xorm:"int pk autoincr unique"`//编号
	Name 		string	`json:"name" xorm:"not null varchar(20)"`//姓名
	University	string	`json:"university" xorm:"not null varchar(20)"`//学校
    Age 		string	`json:"age" xorm:"not null varchar(20)"`//年龄
    Position 	string	`json:"position" xorm:"not null varchar(20)"`//职位
    Gra 		int		`json:"gra" xorm:"not null int"`//授权true/false
}

type Huawei_granted_user struct{
	Id			int		`json:"id" xorm:"int pk autoincr unique"`//编号
	Name 		string	`json:"name" xorm:"not null varchar(20) unique"`//姓名
	University	string	`json:"university" xorm:"not null varchar(20)"`//学校
    Age 		string	`json:"age" xorm:"not null varchar(20)"`//年龄
    Position 	string	`json:"position" xorm:"not null varchar(20)"`//职位
    Gra 		int		`json:"gra" xorm:"not null int"`//授权true/false
}


type Huawei_course struct{
	Id			string	`json:"id" xorm:"not null pk unique"`
	Org			string	`json:"org" xorm:"not null varchar(255)"`
	Name		string	`json:"name" xorm:"not null varchar(255)"`
	Info		string	`json:"info" xorm:"varchar(255)"`
}


type evidenceChian struct{
	id			int
	info		string
	evidence	string
}

func Sql_Huawei_SearchEvidenceChain(fid string)([]evidenceChian,errors){
	mysql := Connection2Huawei()
	SQL :=mysql.Db.NewSession()
	defer SQL.Close()

	RE := []Huawei_evidence{}
	SQL.Table("huawei_evidence").Where("fid = ?",fid).Find(&RE)

	if len(RE) == 0 {
		return errors.New("ERROR EVIDENCE NOT EXIST")
	}

	R := []evidenceChian{}
	for i := 0;i<len(RE);i++ {
		post := &evidenceChian{i,RE[i].info,RE[i].evidence}
		R = append(R,plus)
	}

	return R
}

func Sql_Huawei_InputEvidenceChain(fid,evidence,info string)(errors){
	mysql := Connection2Huawei()
	SQL :=mysql.Db.NewSession()
	defer SQL.Close()

	RE := Huawei_evidence{}
	RE.Fid = fid
	RE.Evidence = evidence
	RE.Info = info

	if _,err := SQL.Insert(RE);err != nil {
		SQL.Rollback()
		errors.New("ERROR EVIDENCE NOT EXIST")
	}

	return nil
}
