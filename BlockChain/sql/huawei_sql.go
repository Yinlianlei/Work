package sql;

import (
	"github.com/pkg/errors"
	"fmt"
	"encoding/json"
	//"time"
)

func Sql_Huawei_Login(name string,university string)error{
	mysql := Connection2Huawei()
	SQL :=mysql.Db.NewSession()
	defer SQL.Close()

	RE := []Huawei_grant2user{}
	SQL.Table("Huawei_grant2user").Where("`name` = ? AND `university` = ?", name,university).Find(&RE)
	
	if(len(RE) != 1 || RE[0].Gra == 0){
		return errors.New("登录失败")
	}

	return nil
}

func Sql_Huawei_Register2GrantUser(id,name,age,position string, Gra int)(string,error){//changed
	mysql := Connection2Huawei()
	SQL :=mysql.Db.NewSession()

	err := SQL.Begin()

	RE := []Huawei_grant2user{}
	SQL.Table("Huawei_grant2user").Where("`name` = ?",name).Find(&RE)
	
	if tmp := len(RE);tmp != 0{
		SQL.Commit()
		SQL.Close()
		return "",errors.New("已注册")
	}

	newUser := new(Huawei_grant2user)
	newUser.Name = name
	newUser.Age = age
	newUser.Position = position
	newUser.Gra = Gra
	newUser.Id = id

	
	_,err = SQL.Insert(newUser)

	if err != nil {
		SQL.Rollback()
		SQL.Close()
		return "",err
	}

	SQL.Commit()
	SQL.Close()
	return "",nil
}

func Sql_Huawei_SearchFid(fid string)(string,error){
	mysql := Connection2Huawei()
	SQL :=mysql.Db.NewSession()
	defer SQL.Close()

	RE := []Huawei_fid_info{}
	SQL.Table("Huawei_fid_info").Where("`fid` = ?",fid).Find(&RE)

	if(len(RE) != 1){
		return "",errors.New("Info查询失败")
	}

	r,err := json.Marshal(RE[0])

	if(err != nil){
		return "查询出现错误",err
	}
	//fmt.Println(string(r))

	return string(r),nil
}

func Sql_Huawei_CheckEvi(fid string, id string)(string,error){
	mysql := Connection2Huawei()
	SQL :=mysql.Db.NewSession()
	defer SQL.Close()

	RE := []Huawei_evidence{}
	SQL.Table("Huawei_evidence").Where("`fid` = ? OR id = ?",fid,id).Find(&RE)

	if(RE == nil){
		return "",errors.New("fid Or id错误")
	}

	r,_ := json.Marshal(RE)
	fmt.Println(string(r))

	return string(r),nil
}

func Sql_Huawei_GetFid(uid string,id string,name string,university string,school string,course string,times int)(string,error){
	mysql := Connection2Huawei()
	SQL :=mysql.Db.NewSession()
	defer SQL.Close()

	RE := []Huawei_fid_info{}
	SQL.Table("Huawei_fid_info").Where("(`uid` = ? AND `name` = ? AND `university` = ? AND `school` = ? AND `course` = ? )",//OR `times` = ? OR id = ?
	uid,name,university,school,course).Find(&RE)

	if(len(RE) == 0){
		return "查询出现错误",errors.New("Error")
	}
	var i = []string{}
	i = append(i,"1")

	r,_ := json.Marshal(RE[0])

	fmt.Println(string(r))

	return string(r),nil
}

func Sql_Huawei_Upload(fid string,uid int,id,name,university,school,course string,times int)(string,error){//v
	mysql := Connection2Huawei()
	SQL :=mysql.Db.NewSession()
	defer SQL.Close()

	RE := new(Huawei_fid_info)

	RE.Fid = fid
	RE.Uid = uid
	RE.Id = id
	RE.Name = name
	RE.University = university
	RE.School = school
	RE.Course = course
	RE.Times = times

	if _,r2 := SQL.Insert(RE);r2 != nil{
		SQL.Rollback()
		return "ERROR INSERT FAILED",r2
	}
	return "",nil
}

func Sql_Huawei_Register2user(id,name,age,pwd,position string,gra int)(string,error){//v//changed
	mysql := Connection2Huawei()
	SQL :=mysql.Db.NewSession()

	TF := []Huawei_grant2user{}
	SQL.Table("huawei_grant2user").Where("name = ? and age = ? and position = ?",name,age,position).Find(&TF)

	if len(TF) != 1 {
		SQL.Close()
		return "",errors.New("NOT GRANTED")
	}

	RE := new(Huawei_granted_user)

	RE.Id = id
	RE.Name = name
	RE.Age = age
	RE.Pwd = pwd
	RE.Position = position
	RE.Gra = gra
	
	err := SQL.Begin()

	_,err = SQL.Insert(RE)

	if err != nil {
		SQL.Rollback()
		SQL.Close()
		return "",err
	}

	de := new(Huawei_grant2user)
	_,err = SQL.Where("name = ? and age = ? and position = ?",name,age,position).Delete(de)
	
	if err != nil {
		SQL.Rollback()
		SQL.Close()
		return "",err
	}

	SQL.Commit()
	SQL.Close()
	return "",nil
}

func Sql_Huawei_CourseUpload(id,org,name,info string)(string,error){
	mysql := Connection2Huawei()
	SQL :=mysql.Db.NewSession()
	defer SQL.Close()

	TF := []Huawei_course{}
	SQL.Table("huawei_course").Where("org = ? and name = ?",org,name).Find(&TF)

	if len(TF) != 0 {
		return "ERROR",errors.New("Course exist")
	}

	RE := new(Huawei_course)
	RE.Id = id
	RE.Org = org
	RE.Name = name
	RE.Info = info

	if _,err := SQL.Insert(RE);err != nil{
		SQL.Rollback()
		return "ERROR",err
	}

	return "",nil
}

func Sql_Huawei_GetCourse(id,org,name string)([]string,error){
	mysql := Connection2Huawei()
	SQL :=mysql.Db.NewSession()
	defer SQL.Close()

	RE := []Huawei_course{}
	SQL.Table("huawei_course").Where("id = ? and org = ? and name = ?",id,org,name).Find(&RE)

	if len(RE) == 0{
		return nil,errors.New("NOT HAS THIS COURSE")
	}

	info := []string{}

	info = append(info,RE[0].Org,RE[0].Name,RE[0].Info)

	return info,nil
}

func Sql_Huawei_StudentLogin(id,pwd string)(error){
	mysql := Connection2Huawei()
	SQL :=mysql.Db.NewSession()
	
	RE := []Huawei_student{}
	SQL.Table("huawei_student").Where("id=? AND pwd=?",id,pwd).Find(&RE)

	if(len(RE) != 1){
		SQL.Close()
		return errors.New("LOGIN FAILD")
	}

	SQL.Close()
	return nil
}

func Sql_Huawei_StudentRegiest(name,uni,sch,id,pwd,uid string)(error){
	mysql := Connection2Huawei()
	SQL :=mysql.Db.NewSession()
	
	RE := new(Huawei_student)
	RE.Name = name
	RE.University = uni
	RE.School = sch
	if id == "" || pwd == "" || uid == "" {
		SQL.Close()
		return errors.New("EROR")
	}

	RE.Id = id
	RE.Pwd = pwd
	RE.Uid = uid

	if _,err := SQL.Insert(RE);err != nil{
		SQL.Rollback()
		SQL.Close()
		return err
	}

	SQL.Close()
	return nil
}

func Sql_Huawei_StudentUpdate(name,uni,sch,uid string)(int64,error){
	mysql := Connection2Huawei()
	SQL :=mysql.Db.NewSession()
	
	RE := new(Huawei_student)
	RE.Name = name
	RE.University = uni
	RE.School = sch

	re,err := SQL.Table("huawei_student").Where("uid = ?",uid).Update(RE)

	if err != nil {
		SQL.Rollback()
		SQL.Close()
		return 1,errors.New("Update failed")
	}
	if re == 0 {
		SQL.Close()
		return re,errors.New("Update failed")
	}

	SQL.Close()
	return re,nil
}

func Sql_Huawei_MemoryInsert(hash string)(error){
	mysql := Connection2Huawei()
	SQL :=mysql.Db.NewSession()

	RE := new(Huawei_memory)
	RE.Hash = hash

	if _,err := SQL.Insert(RE);err != nil{
		SQL.Close()
		return errors.New("Memory insert failed")
	}
	
	SQL.Close()
	return nil
}

func Sql_Huawei_MemoryInsertPlus(hash []string)(error){
	mysql := Connection2Huawei()
	SQL :=mysql.Db.NewSession()

	RE := make([]Huawei_memory,len(hash))
	for i:=0 ; i<len(hash) ; i++{
		RE[i].Hash = hash[i]
	 }
	if _,err := SQL.Insert(&RE);err != nil{
		SQL.Close()
		return errors.New("Memory insert failed")
	}
	SQL.Close()
	return nil
}

func Sql_Huawei_MemoryFunc()([]string){
	mysql := Connection2Huawei()
	SQL :=mysql.Db.NewSession()
	defer SQL.Close()

	RE := []Huawei_memory{}
	SQL.Table("huawei_memory").Find(&RE)

	if len(RE) == 0 {
		return nil
	}
	R := []string{}
	for _,i := range RE {
		R = append(R,string(i.Hash))
	}

	return R
}