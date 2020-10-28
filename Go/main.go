package main
import(
	//"fmt"
	//"time"
	//"encoding/json"
	
)


func main()  {
	//address:="0xb0b811734d04b40ad3d8fa90fa21b7e8fcc1a741133c9815414ebb0f11723112"
	//tmp := "0x0000000000000000000000008719b6f32845bd8ad3abae5f2cc7d9efddf753dc0000000000000000000000008719b6f32845bd8ad3abae5f2cc7d9efddf753dc9e30977b0d2e9a4414618bdf028673feff4e98feea3f3968823bf3f245ed94e2"
	//for i :=0;i< (len(tmp)-2)/64;i++{
	//	fmt.Println((tmp[2+i*64:66+i*64]))
	//}
	

	//TestGetLogByHash(address)
	//TestBlockScanner_Start()
	//spider_contract("1")
	Sql_SelectFromDatabase("data","eth_transaction_log_purchase","")
	//fmt.Println(time.Now().Format("2006-01-02 15:04:05"))
	/*
	mainNet := "https://mainnet.infura.io/v3/2e6d9331f74d472a9d47fe99f697ca2b"
	requestor := NewETHRPCRequester(mainNet)
	il,err := requestor.GetTransactionByHash(address)
	Jjson, _ := json.Marshal(il)
	fmt.Println(string(Jjson),err)
	*/
}