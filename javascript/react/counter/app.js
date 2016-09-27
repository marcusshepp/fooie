import React from 'react';
import ReactDOM from 'react-dom';


// var counter = 0;


class Subtract extends React.Component {
    handle_click(){
        this.props.subtract_from_count();
    }
    render(){
        return (
            <button onClick={ this.handle_click.bind(this) }>--</button>
        );
    }
}


class Count extends React.Component {
    render(){
        return (<p>{ this.props.count }</p>);
    }
}


class Add extends React.Component {
    render(){
        return (
            <button>++</button>
        );
    }
}


class App extends React.Component {

    constructor(){
        super() 
        this.state = {count: 0}
    }

    click_subtract(){
        var new_count = this.state.count - 1;
        this.setState({count: new_count}); 
    }
    click_add(){
        console.log("adding");
    }
	render() {
		return (
            <div>
                <Add click_add={ this.click_add.bind(this) }/>
                { this.state.count }
                <Subtract
                    subtract_from_count={ this.click_subtract.bind(this) } />
            </div>
        );
	}

}


ReactDOM.render(<App />, document.getElementById('app'));
