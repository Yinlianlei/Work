package main
import(
	"fmt"
)

type LatestBlockGetter struct {
	ethRequester ETHRPCRequester    // 以太坊 rpc 请求者实例
}

func NewLatestBlockGetter(requester ETHRPCRequester) *LatestBlockGetter {
	return &LatestBlockGetter{
		ethRequester: requester,
	};
}

func test_Latest_Block(){
	requestor := NewETHRPCRequester(mainNet)
	LB := NewLatestBlockGetter(*requestor)
	n,err :=LB.ethRequester.GetLatestBlockNumber()
	fmt.Println(n,err)
}

