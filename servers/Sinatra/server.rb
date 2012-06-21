require 'sinatra'

set :port, 12345
disable :protection

get '/hello' do
	content_type 'application/json'
	headers "Server" => "Hello"
	'{"responses":{"message":"hello world"}}'
end
