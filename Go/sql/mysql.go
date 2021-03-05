package sql
import(
	"fmt"
	_ "github.com/go-sql-driver/mysql"
	"github.com/go-xorm/xorm"
	"github.com/go-xorm/core"
	"time"
)
type MysqlOptions struct{
	Hostname string
	Port string
	User string
	Password string
	DbName string
	TablePrefix string
	MaxOpenConnections int
	MaxIdleConnections int
	ConnMaxLifetime int
}

type MySQLConnector struct{
	options *MysqlOptions
	tables []interface{}
	Db *xorm.Engine
}

func NewMqSQLConnector(options *MysqlOptions, tables []interface{})MySQLConnector{
	var connector MySQLConnector
	connector.options = options
	connector.tables = tables
	url := ""
	if options.Hostname == "" || options.Hostname == "127.0.0.1" {
		url = fmt.Sprintf(
			"%s:%s@/%s?charset=utf8&parseTime=True",
			options.User,options.Password,options.DbName)
	}else {
		url = fmt.Sprintf(
			"%s:%s@tcp(%s:%s)/%s?charset=utf8&parseTime=True&loc=Local",
			options.User,options.Password,options.Hostname,options.Port,options.DbName)
	}
	db,err := xorm.NewEngine("mysql",url)
	if err != nil {
		panic(fmt.Errorf("DATABASE error in init %s" , err.Error()))
	}
	tbMapper:= core.NewPrefixMapper(core.SnakeMapper{}, options.TablePrefix)
	db.SetTableMapper(tbMapper)
	db.DB().SetConnMaxLifetime(time.Duration(options.ConnMaxLifetime)*time.Second)
	db.DB().SetMaxIdleConns(options.MaxIdleConnections)
	db.DB().SetMaxOpenConns(options.MaxOpenConnections)
	err = db.Ping()
	if err!=nil {
		panic(fmt.Errorf("DATABSE connect faild! %s",err.Error()))
	}
	connector.Db = db
	if err := connector.createTables(); err != nil{
		panic(fmt.Errorf("Create Databse faild! %s",err.Error()))
	}
	return connector
}

func (s *MySQLConnector)createTables() error{
	if err := s.Db.CreateTables(s.tables...);err != nil{
		return fmt.Errorf("Create Mysql table error :%s",err.Error())
	}
	if err:= s.Db.Sync2(s.tables...); err !=nil{
		return fmt.Errorf("Sync tables error:%s",err.Error())
	}
	return nil
}

