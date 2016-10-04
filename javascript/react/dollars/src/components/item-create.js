import React from 'react';

import TextInput from './form/text-input';
import NumberInput from './form/number-input';
import SelectInput from './form/select-input';


export default class ItemCreate extends React.Component {
	render(){
		let options = [
			{
				value: 1,
				display_name: "POD"
			},
			{
				value: 2,
				display_name: "Biggby"
			},
		];
		return (
			<div>
				<TextInput 
					label_text="Name"
					/>
				<TextInput 
					label_text="Where From"
					/>
				<NumberInput
					label_text="Price"
					decimal={ true }
					/>
				<SelectInput
					label_text="Category"
					options={ options }
					/>
			</div>
		);
	}
}



