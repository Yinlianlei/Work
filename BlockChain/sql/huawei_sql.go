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

func Sql_Huawei_Register(name string,university string,age,position string, Gra int)(string,error){
	mysql := Connection2Huawei()
	SQL :=mysql.Db.NewSession()
	defer SQL.Close()

	RE := []Huawei_grant2user{}
	SQL.Table("Huawei_grant2user").Where("`name` = ? AND `university` = ?",name,university).Find(&RE)
	
	
	if(len(RE) != 0){
		return "",errors.New("已注册")
	}

	newUser := new(Huawei_grant2user)
	newUser.Name = name
	newUser.Age = age
	newUser.Position = position
	newUser.Gra = Gra
	newUser.Id = 0
	newUser.University = university

	r1,r2 := SQL.Insert(newUser)

	fmt.Println(r1,r2)

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
		return "",errors.New("查询出现错误")
	}
	var i = []string{}
	i = append(i,"1")

	r,_ := json.Marshal(RE[0])

	fmt.Println(string(r))

	return string(r),nil
}

func Sql_Huawei_upload(fid string,uid int,id,name,university,school,course string,times int)(string,error){//v
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

func Sql_Huawei_Register2user(name,university,age,position string,gra int)(string,error){//v
	mysql := Connection2Huawei()
	SQL :=mysql.Db.NewSession()
	defer SQL.Close()

	RE := new(Huawei_grantedUser)

	RE.Id = 0
	RE.Name = name
	RE.University = university
	RE.Age = age
	RE.Position = position
	RE.Gra = gra

	de := "delete from huawei_grant2user where name = ? and age = ? and position = ?"
	err := SQL.Begin()
	if err != nil {
		SQL.Rollback()
		return "ERROR",errors.New("TRANSACTION BEGIN FAILED")
	}


	if _,err = SQL.Insert(RE);err != nil{
		SQL.Rollback()
		return "ERROR",errors.New("ERROR INSERT FAILED")
	}
	if _,err = SQL.Exec(de,name,age,position);err != nil{
		SQL.Rollback()
		return "ERROR",errors.New("ERROR DELETE GRANT_INFO FAILED")
	}

	err = SQL.Commit()
	if err != nil{
		SQL.Rollback()
		return "ERROR",errors.New("ERROR COMMIT FAILED")
	}


	return "",nil
}