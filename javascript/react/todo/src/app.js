import React from "react";
import ReactDOM from "react-dom";

var Todo = React.createClass({
    render: function() {
        
        return (
            <div>Hello World</div>
        );
        
    }
});

ReactDOM.render(
    <Todo />,
    document.querySelector("#app")
);
