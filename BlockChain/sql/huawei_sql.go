package sql;

import (
	"github.com/pkg/errors"
	"fmt"
	"encoding/json"
	//"time"
)

var mysql = Connection2Huawei()
var SQL =mysql.Db.NewSession()

func Sql_Huawei_Login(name string,university string)error{
	RE := []Huawei_grant2user{}
	SQL.Table("Huawei_grant2user").Where("`name` = ? AND `university` = ?", name,university).Find(&RE)
	
	if(len(RE) != 1 || RE[0].Gra == 0){
		return errors.New("登录失败")
	}

	return nil
}

func Sql_Huawei_Register2GrantUser(id,name,age,position string, Gra int)(string,error){//changed
	err := SQL.Begin()

	RE := []Huawei_grant2user{}
	SQL.Table("Huawei_grant2user").Where("`name` = ?",name).Find(&RE)
	
	if tmp := len(RE);tmp != 0{
		SQL.Commit()
		
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
		return "",err
	}

	SQL.Commit()
	return "",nil
}

func Sql_Huawei_StudyPreAddition(cid,sid,suid string)(error){//用于提前验证是否满足/后续可以考虑删除
	{
		RE := []Huawei_course{}
		SQL.Table("huawei_course").Where("id = ?",cid).Find(&RE)

		if len(RE) != 1 {
			return errors.New("Not this course")
		}
	}

	RE := []Huawei_student{}
	SQL.Table("huawei_student").Where("id = ? AND uid = ?",sid,suid).Find(&RE)

	if len(RE) != 1 {
		return errors.New("Not this student")
	}

	return nil
}

func Sql_Huawei_SearchFid(fid string)(string,error){
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
	TF := []Huawei_grant2user{}
	SQL.Table("huawei_grant2user").Where("name = ? and age = ? and position = ?",name,age,position).Find(&TF)

	if len(TF) != 1 {
		
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
		return "",err
	}

	de := new(Huawei_grant2user)
	_,err = SQL.Where("name = ? and age = ? and position = ?",name,age,position).Delete(de)
	
	if err != nil {
		SQL.Rollback()
		return "",err
	}

	SQL.Commit()
	return "",nil
}

func Sql_Huawei_CourseUpload(id,org,name,info string)(string,error){
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
	RE := []Huawei_course{}
	SQL.Table("huawei_course").Where("id = ? and org = ? and name = ?",id,org,name).Find(&RE)

	if len(RE) == 0{
		return nil,errors.New("NOT HAS THIS COURSE")
	}

	info := []string{}

	info = append(info,RE[0].Org,RE[0].Name,RE[0].Info)

	return info,nil
}

func Sql_Huawei_SearchEvidenceChain(fid string)([]EvidenceChian,error){
	RE := []Huawei_evidence{}
	SQL.Table("huawei_evidence").Where("fid = ?",fid).Find(&RE)

	if len(RE) == 0 {
		return nil,nil
		//errors.New("ERROR EVIDENCE NOT EXIST")
	}

	R := []EvidenceChian{}
	for i := 0;i<len(RE);i++ {
		post := EvidenceChian{i,RE[i].Info,RE[i].Evidence}
		R = append(R,post)
	}

	return R,nil
}

func Sql_Huawei_InputEvidenceChain(fid,evidence,info string,grade float32)(error){
	RE := Huawei_evidence{}
	RE.Fid = fid
	RE.Evidence = evidence
	RE.Info = info
	RE.Grade = grade

	if _,err := SQL.Insert(RE);err != nil {
		SQL.Rollback()
		errors.New("ERROR EVIDENCE NOT EXIST")
	}

	return nil
}


func Sql_Huawei_StudentLogin(id,pwd string)(error){
	RE := []Huawei_student{}
	SQL.Table("huawei_student").Where("id=? AND pwd=?",id,pwd).Find(&RE)

	if(len(RE) != 1){
		
		return errors.New("LOGIN FAILD")
	}

	
	return nil
}

func Sql_Huawei_StudentRegiest(name,uni,sch,schid,id,pwd,uid string)(error){
	RE := new(Huawei_student)
	RE.Name = name
	RE.University = uni
	RE.School = sch
	RE.SchId = schid
	if id == "" || pwd == "" || uid == "" {
		
		return errors.New("EROR")
	}

	RE.Id = id
	RE.Pwd = pwd
	RE.Uid = uid

	if _,err := SQL.Insert(RE);err != nil{
		SQL.Rollback()
		
		return err
	}

	return nil
}

func Sql_Huawei_StudentUpdate(name,uni,sch,schid,uid string)(int64,error){
	RE := new(Huawei_student)
	RE.Name = name
	RE.University = uni
	RE.School = sch
	RE.SchId = schid

	re,err := SQL.Table("huawei_student").Where("uid = ?",uid).Update(RE)

	if err != nil {
		SQL.Rollback()
		
		return 1,errors.New("Update failed")
	}
	if re == 0 {
		
		return re,errors.New("Update failed")
	}

	
	return re,nil
}

func Sql_Huawei_MemoryInsert(hash string)(error){
	RE := new(Huawei_memory)
	RE.Hash = hash

	if _,err := SQL.Insert(RE);err != nil{
		
		return errors.New("Memory insert failed")
	}
	
	
	return nil
}

func Sql_Huawei_MemoryInsertPlus(hash []string)(error){
	RE := make([]Huawei_memory,len(hash))
	for i:=0 ; i<len(hash) ; i++{
		RE[i].Hash = hash[i]
	 }
	if _,err := SQL.Insert(&RE);err != nil{
		
		return errors.New("Memory insert failed")
	}
	
	return nil
}

func Sql_Huawei_MemoryFunc()([]string){
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

func Sql_Huawei_StudentFinish(fid string)(error){
	RE := new(Huawei_fid_info)
	RE.Status = "Finished"
	re,err := SQL.Table("huawei_fid_info").Where("fid = ?",fid).Update(RE)

	if err != nil {
		SQL.Rollback()
		
		return err
	}
	if re == 0 {
		SQL.Rollback()
		
		return errors.New("Update failed")
	}

	
	return nil
}

func Sql_Huawei_CourseEndorseInsert(cid,university string)(error){
	{
		Find := []Huawei_courseEndorse{}

		SQL.Table("huawei_course_endorse").Where("course_id = ? and endorse_university = ?",cid,university).Find(&Find)

		if len(Find)!=0 {
			return errors.New("Endorse exist")
		}
	}

	RE := new(Huawei_courseEndorse)
	RE.CourseId = cid
	RE.EndorseUniversity = university

	if _,err:= SQL.Insert(RE);err != nil {
		return err
	}

	return nil
}

func Sql_Huawei_CourseEndorseDelete(cid,university string)(error){
	{
		Find := []Huawei_courseEndorse{}

		SQL.Table("huawei_course_endorse").Where("course_id = ? and endorse_university = ?",cid,university).Find(&Find)
		
		if len(Find) == 0 {
			return errors.New("Endorse not exist")
		}
	}
	
	RE := new(Huawei_courseEndorse)
	
	_,err := SQL.Table("huawei_course_endorse").Where("course_id = ? and endorse_university = ?",cid,university).Delete(RE)
	if err != nil {
		return err
	}

	return nil
}

func Sql_Huawei_SearchTimes(uid,cid string)(int,error){
	Stu := []Huawei_student{}
	Cour := []Huawei_course{}
	RE := []Huawei_fid_info{}
	SQL.Table("huawei_student").Where("uid = ?",uid).Find(&Stu)
	//fmt.Println(Stu[0])
	SQL.Table("huawei_course").Where("id = ?",cid).Find(&Cour)
	//fmt.Println(Cour[0])
	SQL.Table("huawei_fid_info").Where("course = ? and id = ? and name = ?",Cour[0].Name,Stu[0].SchId,Stu[0].Name).Find(&RE)

	if len(RE) == 0 {
		
		return 0,errors.New("FIND FAILD")
	}
	
	return RE[0].Times,nil
}

func Sql_Huawei_ConnectClose(){
	SQL.Close()
}
/*
time1 := time.Now().Unix()
	time2 := time.Now().Unix()
	for i:=0 ; i<20 ; i++ {
		//In = append(In,strconv.Itoa(i*200))
		In := strconv.Itoa(i)
		fmt.Println(sql.Sql_Huawei_MemoryInsert(In))
		time2 = time.Now().Unix()
		time.Sleep(2 * time.Second)
		fmt.Println(time1,time2)
		if time2 - time1 >= 10 { 
			time1 = time2
			go fmt.Println(sql.Sql_Huawei_MemoryFunc())
		}
	}
*/