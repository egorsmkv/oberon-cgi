package main

import (
	"fmt"
	"net/http"
	"net/http/cgi"
)

func hwHandler(w http.ResponseWriter, r *http.Request) {
	handler := cgi.Handler{Path: "compiled/HelloWorld"}
	handler.ServeHTTP(w, r)
}

func peHandler(w http.ResponseWriter, r *http.Request) {
	handler := cgi.Handler{Path: "compiled/PrintEnvs"}
	handler.ServeHTTP(w, r)
}

func stHandler(w http.ResponseWriter, r *http.Request) {
	handler := cgi.Handler{Path: "compiled/ServerTime"}
	handler.ServeHTTP(w, r)
}

func main() {
	http.HandleFunc("/hello-world", hwHandler)
	http.HandleFunc("/print-envs", peHandler)
	http.HandleFunc("/server-time", stHandler)

	fmt.Println("The web server started at http://localhost:8080")

	http.ListenAndServe("localhost:8080", nil)
}
