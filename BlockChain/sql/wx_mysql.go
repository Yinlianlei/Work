package sql;

import (
	"github.com/pkg/errors"
	"fmt"
	//"time"
)
//import t "eth-relay/go-sdk/storeKey"

func Sql_Wx_Login(id string,pwd string)error{
	mysql := Connection2copy()
	SQL :=mysql.Db.NewSession()
	defer SQL.Close()

	RE := []Wx_user{}
	SQL.Table("user").Where("`Owner` = ? AND `Pwd` = ?", id,pwd).Find(&RE)

	fmt.Println(RE[0])
	if(len(RE) != 1){
		return errors.New("登录失败")
	}

	return nil
}
/*
func Sql_Wx_ConfirmCopyright(data t.CopyRight)error{
	mysql := Connection2copy()
	SQL :=mysql.Db.NewSession()
	defer SQL.Close()

	RE := Wx_copyright{}
	RE.Owner = data.Owner
	RE.FileName = data.Filename
	RE.Hash = data.Hash
	RE.FileID = data.FileID
	RE.TxID = data.TxId
	RE.Time = time.Unix(0,data.Time)

	if _, err := SQL.Insert(&RE); err != nil{//insert
		SQL.Rollback()
		return err
	}

	return nil
}

func Sql_Wx_Purchase(data t.Purchase)error{
	mysql := Connection2copy()
	SQL :=mysql.Db.NewSession()
	defer SQL.Close()

	RE := Wx_purchase{}
	RE.Owner = data.Owner
	RE.Purchase = data.Buyer
	RE.Hash = data.Hash
	RE.Price = data.Price
	RE.TxID = data.TxId

	if _, err := SQL.Insert(&RE); err != nil{//insert
		SQL.Rollback()
		return err
	}

	return nil
}
*/