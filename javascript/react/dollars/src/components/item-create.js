import React from 'react';

import TextInput from './form/text-input';
import NumberInput from './form/number-input';
import SelectInput from './form/select-input';
import SubmitButton from './form/submit-btn';

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
			<form 
				method="POST"	
				action={ this.props.action }>
				<TextInput 
					label_text="Name"
					include_label={ true }
					/>
				<TextInput 
					label_text="Where From"
					include_label={ true }
					/>
				<NumberInput
					label_text="Price"
					decimal={ true }
					include_label={ true }
					/>
				<SelectInput
					label_text="Category"
					options={ options }
					/>
				<SubmitButton />
			</form>
		);
	}
}



