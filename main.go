package main

import (
	"fmt"
	"io"
	"log"
	"net/http"
)

func main() {
	client := &http.Client{}
	req, err := http.NewRequest("GET", "https://kick.com/api/v2/channels/test/", nil)
	if err != nil {
		log.Fatal(err)
	}
	req.Header.Set("User-Agent", "Mozilla/5.0 (X11; Linux x86_64; rv:69.0) Gecko/20100101 Firefox/69.0")
	req.Header.Set("Accept", "text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8")
	req.Header.Set("Accept-Language", "en-US,en;q=0.5")
	req.Header.Set("Connection", "keep-alive")
	req.Header.Set("Cookie", "__cfduid=d2968dfaa76dada580b923fac7e093d061571294263; AWSALB=Uu9vE1HnWlW5TXbouXY0sTfE4qQRtz03MnAAKwQTmhIxtoB31dYXFN6PIpEcdUjphZ+i/ynkJ4he6kFw0X5CFQ8LpRUhR5YbSxUhlBb2zododhGDFcq+UOvX8hka; Unique_ID_v2=d316b882e38649459fe3a24112658486; __cf_bm=e916e894150611cfd4a67e54c805e5e09eaab98b-1571294263-1800-AWCGwtWV/1I1oFisZ7DplVhsoDuIV8fNBu+htwA+La56jXRF9No3bdeQgM0rdTUy7hC7GQmU8ZtswVHONBzsl2I=; ResponsiveSwitch.DesktopMode=1")
	req.Header.Set("Upgrade-Insecure-Requests", "1")
	req.Header.Set("Cache-Control", "max-age=0")
	req.Header.Set("TE", "Trailers")
	resp, err := client.Do(req)
	if err != nil {
		log.Fatal(err)
	}
	defer resp.Body.Close()
	bodyText, err := io.ReadAll(resp.Body)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Printf("%s\n", bodyText)
}
